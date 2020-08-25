#include <QCoreApplication>

/*
 What:
 Exception safety
 https://en.wikipedia.org/wiki/Exception_safety

 Decription:
  Make it as strong as you can!

 Why:
 Bad things happen!!

 Example:
 to do - find the flaws in this example!

 */

#include <QFile>
#include <QDebug>

bool toFile(QString path, QString data)
{
    if(path.isEmpty() || data.isEmpty()) return false;

    QFile file(path);
    if(!file.open(QIODevice::WriteOnly))
    {
        qWarning() << file.errorString();
        return false;
    }

    bool ok = false;
    if(file.write(data.toUtf8()) > 0)
    {
        ok = true;
    }
    else
    {
        qWarning() << file.errorString();
    }

    file.close();
    return ok;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = "test.txt";
    QString data = "Millions of Cats";

    if(toFile(path,data))
    {
        qInfo() << "Success!";
    }
    else
    {
        qWarning() << "Failed!";
    }


    return a.exec();
}
