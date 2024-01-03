#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include "../BackWaterways/class/Headers/usuario.hpp"
#ifndef LOGINCADASTRODIALOG_HPP
#define LOGINCADASTRODIALOG_HPP

class LoginCadastroDialog : public QDialog {
    Q_OBJECT

public:
    LoginCadastroDialog(QWidget* parent = nullptr);

private slots:
    void realizarLogin();
    void realizarCadastro();

private:
    QLineEdit* nomeUsuarioLineEdit;
    QLineEdit* senhaLineEdit;
    QPushButton* loginButton;
    QPushButton* cadastroButton;
};

#endif // LOGINCADASTRODIALOG_HPP
