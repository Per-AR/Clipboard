#include <QtWidgets>

class ClipboardApp : public QMainWindow {
    Q_OBJECT

public:
    ClipboardApp(QWidget *parent = nullptr) : QMainWindow(parent) {
        setWindowTitle("Futuristic Clipboard Manager");
        setFixedSize(400, 300);

        // Text area
        textEdit = new QTextEdit(this);
        textEdit->setStyleSheet("font: 12pt Arial;");
        setCentralWidget(textEdit);

        // Copy button
        copyButton = new QPushButton(this);
        copyButton->setIcon(QIcon("copy.png"));
        copyButton->setFixedSize(32, 32);
        connect(copyButton, &QPushButton::clicked, this, &ClipboardApp::copy);
        
        // Paste button
        pasteButton = new QPushButton(this);
        pasteButton->setIcon(QIcon("paste.png"));
        pasteButton->setFixedSize(32, 32);
        connect(pasteButton, &QPushButton::clicked, this, &ClipboardApp::paste);

        // Clear button
        clearButton = new QPushButton(this);
        clearButton->setIcon(QIcon("clear.png"));
        clearButton->setFixedSize(32, 32);
        connect(clearButton, &QPushButton::clicked, this, &ClipboardApp::clear);

        // Layout
        QHBoxLayout *buttonLayout = new QHBoxLayout;
        buttonLayout->addWidget(copyButton);
        buttonLayout->addWidget(pasteButton);
        buttonLayout->addWidget(clearButton);
        
        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(textEdit);
        mainLayout->addLayout(buttonLayout);

        QWidget *centralWidget = new QWidget(this);
        centralWidget->setLayout(mainLayout);
        setCentralWidget(centralWidget);
    }

private slots:
    void copy() {
        QString selectedText = textEdit->textCursor().selectedText();
        QApplication::clipboard()->setText(selectedText);
    }

    void paste() {
        QString clipboardText = QApplication::clipboard()->text();
        textEdit->insertPlainText(clipboardText);
    }

    void clear() {
        textEdit->clear();
    }

private:
    QTextEdit *textEdit;
    QPushButton *copyButton;
    QPushButton *pasteButton;
    QPushButton *clearButton;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ClipboardApp window;
    window.show();
    return app.exec();
}

#include "main.moc"
