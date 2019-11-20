#include "mapwindow.hh"
#include <QApplication>
#include <QDialog>
#include <QObject>
#include "startdialog.hh"
#include "setplayerdialog.hh"
#include "gameeventhandler.hh"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    std::shared_ptr<GameEventHandler> handler = std::make_shared<GameEventHandler>();

    MapWindow mapWindow;

    mapWindow.setGEHandler(handler);

    // Dialog to start the game
    StartDialog startDialog;


    // Dialog to set the number of players in the game
    SetPlayerDialog setPlayerDialog;

    // Open setPlayerDialog when the play button is clicked
    QDialog::connect(&startDialog, SIGNAL(openSetPlayers()), &setPlayerDialog, SLOT(exec()));

    // Set the number of players in the game
    QDialog::connect(&setPlayerDialog, SIGNAL(startGame(int)),&mapWindow, SLOT(createPlayers(int)));

    startDialog.exec();







    return app.exec();
}
