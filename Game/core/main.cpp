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
    int appExitCode;
    do {
        QApplication app(argc, argv);

        std::shared_ptr<Student::GameEventHandler> handler = std::make_shared<Student::GameEventHandler>();

        MapWindow mapWindow(0, handler);


        // Dialog to start the game
        StartDialog startDialog;

        // Dialog to set the number of players in the game
        SetPlayerDialog setPlayerDialog;

        // Open setPlayerDialog when the play button is clicked
        QDialog::connect(&startDialog, SIGNAL(openSetPlayers()), &setPlayerDialog, SLOT(exec()));

        // Set the number of players in the game
        QDialog::connect(&setPlayerDialog, SIGNAL(startGame(int)),&mapWindow, SLOT(createPlayers(int)));

        // Stop the game if the startDialog get deleted.
        if (startDialog.exec() == QDialog::Rejected){
            appExitCode = 0;
        } else {
            appExitCode = app.exec();
        }


    } while (appExitCode == 200);

    return appExitCode;
}
