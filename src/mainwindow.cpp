#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Force a classic vertical smartphone aspect ratio on desktop window initialization
    setFixedSize(450, 800); 
    setWindowTitle("RetroFuse Emulator (Qt6)");

    // Initialize the OpenGL canvas container where the core engines will render frames
    m_gameCanvas = new QOpenGLWidget(this);
    m_gameCanvas->setStyleSheet("background-color: #111111;");

    setCentralWidget(m_gameCanvas);
}

MainWindow::~MainWindow() {}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->isAutoRepeat()) return; // Bypass native OS keyboard repeat delays

    switch (event->key()) {
        case Qt::Key_W:     sendKeyToEngine(1, true);  break; // DPAD_UP
        case Qt::Key_S:     sendKeyToEngine(2, true);  break; // DPAD_DOWN
        case Qt::Key_A:     sendKeyToEngine(3, true);  break; // DPAD_LEFT
        case Qt::Key_D:     sendKeyToEngine(4, true);  break; // DPAD_RIGHT
        case Qt::Key_Z:     sendKeyToEngine(5, true);  break; // FIRE / SELECT (Button A)
        case Qt::Key_X:     sendKeyToEngine(8, true);  break; // CLEAR / BACK (Button B)
        case Qt::Key_Q:     sendKeyToEngine(-6, true); break; // Left Soft Key (LSK)
        case Qt::Key_E:     sendKeyToEngine(-7, true); break; // Right Soft Key (RSK)
        
        // Dynamic interception of top-row standard numeric keys
        case Qt::Key_0: case Qt::Key_1: case Qt::Key_2: case Qt::Key_3:
        case Qt::Key_4: case Qt::Key_5: case Qt::Key_6: case Qt::Key_7:
        case Qt::Key_8: case Qt::Key_9:
            sendKeyToEngine(event->key() - Qt::Key_0, true);
            break;
            
        default:
            QMainWindow::keyPressEvent(event);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    if (event->isAutoRepeat()) return; // Protect holding vectors during key lifts

    switch (event->key()) {
        case Qt::Key_W:     sendKeyToEngine(1, false);  break;
        case Qt::Key_S:     sendKeyToEngine(2, false);  break;
        case Qt::Key_A:     sendKeyToEngine(3, false);  break;
        case Qt::Key_D:     sendKeyToEngine(4, false);  break;
        case Qt::Key_Z:     sendKeyToEngine(5, false);  break;
        case Qt::Key_X:     sendKeyToEngine(8, false);  break;
        case Qt::Key_Q:     sendKeyToEngine(-6, false); break;
        case Qt::Key_E:     sendKeyToEngine(-7, false); break;
        default:
            QMainWindow::keyReleaseEvent(event);
    }
}

void MainWindow::sendKeyToEngine(int legacyKeyCode, bool isPressed) {
    // This logs the input vector before channeling directly into the engine threads
    qDebug() << "Key Event Map Index:" << legacyKeyCode << " | State Pressed:" << isPressed;
}