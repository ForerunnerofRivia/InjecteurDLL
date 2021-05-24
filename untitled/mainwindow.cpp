#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->scrollArea->setBackgroundRole(QPalette::Light);
    widget = new QWidget;
    layoutScrollarea = new QVBoxLayout(widget);
    ui->scrollArea->setWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dllbtn_clicked()
{
    dllPath = QFileDialog::getOpenFileName(this,
                                                     tr("Sélectionnez un fichier"),
                                                        "",
                                                         "Dll (*.dll)");
    ui->pathlabel->setText(dllPath);
}

void MainWindow::on_scanbtn_clicked()
{
   processList.clear();
   int errorScan = 0;
   errorScan = getProcessList();
   if(errorScan){
       QMessageBox msgBox;
       msgBox.setText("Erreur lors du scan des processus");
       msgBox.setStandardButtons(QMessageBox::Ok);
       msgBox.exec();
       return;
   }

   for(int i = 0; i < processList.size();i++){
       layoutScrollarea->addWidget(processList[i]->checkbox);
       processList[i]->checkbox->show();
   }



}


int MainWindow::getProcessList(){
    // Get the list of process identifiers.
        cleanCheckBoxes();

        DWORD aProcesses[1024], cbNeeded, cProcesses;
        unsigned int i;

        if ( !EnumProcesses( aProcesses, sizeof(aProcesses), &cbNeeded ) )
        {
            QMessageBox msgBox1;
            msgBox1.setText("Erreur : EnumProcess");
            msgBox1.setStandardButtons(QMessageBox::Ok);
            msgBox1.exec();
            return 1;
        }


        // Calculate how many process identifiers were returned.

        cProcesses = cbNeeded / sizeof(DWORD);

        // Print the name and process identifier for each process.

        for ( i = 0; i < cProcesses; i++ )
        {
            if( aProcesses[i] != 0 )
            {
                PrintProcessNameAndID( aProcesses[i] );
            }
        }
        return 0;
}

void MainWindow::PrintProcessNameAndID( DWORD processID )
{

    TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

    // Get a handle to the process.

    HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
                                   PROCESS_VM_READ,
                                   FALSE, processID );

    // Get the process name.

    if (NULL != hProcess )
    {
        HMODULE hMod;
        DWORD cbNeeded;

        if ( EnumProcessModules( hProcess, &hMod, sizeof(hMod),
             &cbNeeded) )
        {
            GetModuleBaseName( hProcess, hMod, szProcessName,
                               sizeof(szProcessName)/sizeof(TCHAR) );
        }
        else{
            return;
        }
        // Print the process name and identifier.

        //_tprintf( TEXT("%s  (PID: %u)\n"), szProcessName, processID );
        // Release the handle to the process.
        std::wstring ws(szProcessName);
        std::string str(ws.begin(),ws.end());
        QCheckBox * crCheckBox = new QCheckBox(str.c_str(),this);

        tuplessucks * crStruct = (tuplessucks*)malloc(sizeof(tuplessucks));
        crStruct->checkbox = crCheckBox;
        crStruct->name = szProcessName;
        crStruct->pid = processID;

        this->processList.push_back(crStruct);
        CloseHandle( hProcess );
    }
    else{
        return;
    }


}

void MainWindow::cleanCheckBoxes(){

    for(int i = 0; i < processList.size();i++){
        processList[i]->checkbox->setCheckState(Qt::CheckState::Unchecked);
        processList[i]->checkbox->deleteLater();
        layoutScrollarea->removeWidget(processList[i]->checkbox);
        delete processList[i]->checkbox;
    }


    processList.clear();

}


void MainWindow::getprocessToinject(){
    for(int i = 0; i < processList.size();i++){
       if(processList[i]->checkbox->checkState()){
           this->pid = processList[i]->pid;
       }
    }
}

void MainWindow::on_injectbtn_clicked()
{
    this->pid = 0;
    getprocessToinject();

}

void MainWindow::injectLoadLibrary(){
    if(this->pid == 0){
        QMessageBox msgBox2;
        msgBox2.setText("Erreur : Recupération de l'ID du processus séléctionné");
        msgBox2.setStandardButtons(QMessageBox::Ok);
        msgBox2.exec();
        return;
    }


}

