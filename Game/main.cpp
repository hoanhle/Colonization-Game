#include "mapwindow.hh"
#include "startdialog.hh"
#include <QApplication>
#include <QDialog>

int main(int argc, char* argv[])
{

    QApplication app(argc, argv);

    MapWindow mapWindow;

    StartDialog startdialog;
    if (startdialog.exec() == QDialog::Accepted){
        mapWindow.show();
    }

    return app.exec();
}
