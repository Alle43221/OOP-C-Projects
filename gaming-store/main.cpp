#include <QApplication>
#include <QPushButton>
#include "Service.h"
#include "GUI.h"

int main(int argc, char *argv[]) {
    Repo my_repo("jocuri.txt");
    Service my_srv(my_repo);

    QApplication a(argc, argv);
    GUI c(my_srv);
    c.show();
    return QApplication::exec();
}
