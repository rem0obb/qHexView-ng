QHexView-ng
==========

This is Qt widget for display binary data in traditional hex-editor style. This widget doesn`t have any editing capabilities. Only viewing and copying.


GUI
-----

![image](assets/qhexview-ng.png)


Building the example
-----

* cd  QHexView-ng
* mkdir build
* cd build
* cmake ..
* make


Usage Widget Application
-----
	#include <QVBoxLayout>
	...

	QVBoxLayout *m_layout = new QVBoxLayout;
	QHexView *qHexView = new QHexView;

	...

	qHexView->loadFile("to/path/file");

	...

	m_layout->addWidget(m_hexview);
	m_ui->widgetHex->setLayout(m_layout);
