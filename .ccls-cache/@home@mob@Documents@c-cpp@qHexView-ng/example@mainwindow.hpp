#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>

#include "../src/include/QHexView-ng.hpp"

namespace Ui
{
    class MainWindow;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget * = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionGo_to_Offset_triggered();

    void on_actionAbout_triggered();

private:
	Ui::MainWindow *m_ui;
	QHexView* m_hexview;
	QVBoxLayout* m_layout;
	QString m_fileName;

	void confWidget();
	void loadFile();
};
