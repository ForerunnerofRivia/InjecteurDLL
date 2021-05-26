#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QString>
#include <QFileDialog>
#include <Windows.h>
#include <vector>
#include <tuple>
#include <QCheckBox>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>
#include <QMessageBox>
#include <QLayout>
#include <QScrollArea>
#include <QWidget>
#include <thread>

struct tuplessucks{
    TCHAR* name;
    DWORD pid;
    QCheckBox* checkbox;
};

void dothebarthing(int sleep);
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int getProcessList();
    void PrintProcessNameAndID( DWORD processID );
    void cleanCheckBoxes();
    void getprocessToinject();
    void injectLoadLibrary();
    void dothebarthing(int sleep, QProgressBar * b);
private:
    QString dllPath;
    std::vector<tuplessucks*> processList;
    QVBoxLayout * layoutScrollarea;
    QWidget * widget;
    DWORD pid;

private slots:
    void on_dllbtn_clicked();

    void on_scanbtn_clicked();

    void on_injectbtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
