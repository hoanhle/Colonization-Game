#include "graphics/mapwindow.hh"
#include <QApplication>
#include <QDialog>
#include <QObject>
#include "graphics/startdialog.hh"
#include "graphics/setplayerdialog.hh"
#include "core/gameeventhandler.hh"
#include "graphics/rulesdialog.hh"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    std::shared_ptr<GameEventHandler> handler = std::make_shared<GameEventHandler>();

    MapWindow mapWindow(0, handler);


    // Dialog to start the game
    StartDialog startDialog;

    // Dialog to set the number of players in the game
    SetPlayerDialog setPlayerDialog;

    // Dialog to show how to play
    RulesDialog rulesDialog;

    // Open rulesDialog when the how to play button is clicked
    QDialog::connect(&startDialog, SIGNAL(openRules()), &rulesDialog, SLOT(show()));

    // Back to startDialog when back button is clicked
    QDialog::connect(&rulesDialog, SIGNAL(backToStart()), &startDialog, SLOT(show()));

    // Open setPlayerDialog when the play button is clicked
    QDialog::connect(&startDialog, SIGNAL(openSetPlayers()), &setPlayerDialog, SLOT(exec()));

    // Set the number of players in the game
    QDialog::connect(&setPlayerDialog, SIGNAL(startGame(int)),&mapWindow, SLOT(createPlayers(int)));

    // Stop the game if the startDialog get deleted.
    if (startDialog.exec() != QDialog::Accepted){
        return app.exec();
    }

    rulesDialog.exec();







    return app.exec();
}
