#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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


struct tuplessucks{
    TCHAR* name;
    DWORD pid;
    QCheckBox* checkbox;
};


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
private:
    QString dllPath;
    std::vector<tuplessucks*> processList;
    QVBoxLayout * layoutScrollarea;
    QWidget * widget;

private slots:
    void on_dllbtn_clicked();

    void on_scanbtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
