#ifndef Music_H
#define Music_H

#include <QMainWindow>
#include <iostream>
#include <iomanip>

namespace Ui {
class Music;
}

class Music : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Music(QWidget *parent = 0);
    
private slots:

    bool on_actionSave_as_triggered();

    bool on_action_Save_triggered();

    void on_action_Open_triggered();

    void closeEvent(QCloseEvent *event);

    void openRecentFile();


    void on_pushButtonPlay_clicked();

    void on_pushButtonStop_clicked();

    void on_radioButtonFiltre_clicked(bool checked);

private:
    Ui::Music *ui;
    bool saveFile(const QString &fileName);
    bool maybeSave();
    void readSettings();
    void writeSettings();
    void setCurrentFile(const QString &fileName);
    void updateRecentFileActions();
    void loadFile(const QString &fileName);
    QString curFile;

    enum {MaxRecenFiles = 5};
    QAction *recentFilesActs[MaxRecenFiles];
};

#endif // Music_H
