#include <QCoreApplication>
#include <QTcpSocket>
#include <QTcpServer>
#include <string>
#include <QThread>
using namespace std;

class Worker : public QThread
{
public:
    int port;
    void run(){

        QTcpServer server;
        if (!server.listen(QHostAddress::Any, port)) {
            qDebug()<<"error";
        }

        server.waitForNewConnection(-1);
        QTcpSocket* socket = server.nextPendingConnection();

        if (socket!= NULL) {
            qDebug()<<"connected";
        }

        while (socket->state() == QAbstractSocket::ConnectedState) {
            if (socket->waitForReadyRead(-1)) {
                QByteArray d = socket->readAll();
                if (d.length() > 0) {
                    qDebug()<<d.constData();
                    string message = "acknowledged";
                    QByteArray response(message.c_str(), message.length());
                    socket->write(response);
                }

            }
        }
    }
    void setPort(int num){
        this->port = num;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Worker* thread1 = new Worker();
    Worker* thread2 = new Worker();
    thread1->setPort(7000);
    thread2->setPort(6000);
    thread1->start();
    thread2->start();

    thread1->wait();
    thread2->wait();
    return a.exec();
}
