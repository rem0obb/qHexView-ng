#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *p_parent) : QMainWindow(p_parent),
								 m_ui(new Ui::MainWindow),
								 m_layout(new QVBoxLayout),
								 m_hexview(new QHexView)
{
	m_ui->setupUi(this);
	confWidget();
}

MainWindow::~MainWindow()
{
	delete m_ui;
	delete m_hexview;
	delete m_layout;
}

void MainWindow::confWidget()
{
	// hex editor Tab
	m_layout->addWidget(m_hexview);
	m_ui->widgetHex->setLayout(m_layout);
}

void MainWindow::on_actionOpen_triggered()
{
	QFileDialog dialog(this);
   	dialog.setFileMode(QFileDialog::ExistingFile);

   	dialog.exec();
   	if (dialog.selectedFiles().count() != 1)
	  	return;

   	m_fileName = dialog.selectedFiles().at(0);
	loadFile();
}

void MainWindow::loadFile()
{
	try
	{
		m_hexview->loadFile(m_fileName);

	}catch(std::exception &e)
	{
	    std::string errorMessage("Loading Error: ");
            errorMessage.append(e.what());

            QMessageBox msgBox;
            msgBox.setText(errorMessage.c_str());
            msgBox.exec();
            return;
	}
}


void MainWindow::on_actionGo_to_Offset_triggered()
{
	bool ok;
	int offset = QInputDialog::getInt(0, "Offset", "Offset:", 0, 0, 2147483647, 1, &ok);

	if (ok)
        	m_hexview->showFromOffset(offset);
}

void MainWindow::on_actionAbout_triggered()
{
    QString message("<center><b>QHexView-ng example</b></center>");
    message.append("<center>mobhacking100@gmail.com</center>");
    QMessageBox::about(this, "About", message);
}

void MainWindow::on_pushButton_clicked()
{
   on_actionOpen_triggered();
}

void MainWindow::on_actionClean_triggered()
{
    m_hexview->clear();
}

