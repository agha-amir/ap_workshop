#include <QCoreApplication>
#include <QTcpSocket>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTcpSocket socket;
    socket.connectToHost("127.0.0.1", 7000);
    if (socket.waitForConnected(6000)) {
        qDebug()<<"connected";
    }
    else{qDebug()<<"connection error";}

    while (socket.state() == QAbstractSocket::ConnectedState) {
        string message;
        getline(cin, message);
        QByteArray d(message.c_str(), message.length());
        if (socket.write(d) < 0)
            qDebug()<<"error in sending";
        if (socket.waitForReadyRead(-1)){
            QByteArray response = socket.readAll();
            if (response.length() > 0) {
                qDebug()<<response.constData();
            }
        }
    }

    return a.exec();
}
