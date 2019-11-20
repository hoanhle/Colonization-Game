#include "mapwindow.hh"
#include <QApplication>
#include <QDialog>
#include <QObject>
#include "startdialog.hh"
#include "setplayerdialog.hh"



int main(int argc, char* argv[])
{

    QApplication app(argc, argv);

    MapWindow mapWindow;

    // Dialog to start the game
    StartDialog startDialog;


    // Dialog to set the number of players in the game
    SetPlayerDialog setPlayerDialog;


    QDialog::connect(&startDialog, SIGNAL(openSetPlayers()), &setPlayerDialog, SLOT(exec()));
    QDialog::connect(&setPlayerDialog, SIGNAL(startGame()), &mapWindow, SLOT(show()));
    startDialog.exec();







    return app.exec();
}
