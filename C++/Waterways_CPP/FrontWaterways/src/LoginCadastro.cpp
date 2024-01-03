#include "../Headers/LoginCadastro.hpp"

LoginCadastroDialog::LoginCadastroDialog(QWidget* parent)
    : QDialog(parent) {
    nomeUsuarioLineEdit = new QLineEdit(this);
    senhaLineEdit = new QLineEdit(this);
    senhaLineEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Login", this);
    cadastroButton = new QPushButton("Cadastrar", this);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(nomeUsuarioLineEdit);
    layout->addWidget(senhaLineEdit);
    layout->addWidget(loginButton);
    layout->addWidget(cadastroButton);

    connect(loginButton, &QPushButton::clicked, this, &LoginCadastroDialog::realizarLogin);
    connect(cadastroButton, &QPushButton::clicked, this, &LoginCadastroDialog::realizarCadastro);
}

void LoginCadastroDialog::realizarLogin() {
    QString nomeUsuario = nomeUsuarioLineEdit->text();
    QString senha = senhaLineEdit->text();

    // Lógica de verificação de login
    // Exemplo simples: verificar se o nome de usuário e senha correspondem a um usuário existente
    Usuario usuarioExistente(nomeUsuario.toStdString(), "email", senha.toStdString(), 1, 25, 70.0, true);

    if (nomeUsuario == QString::fromStdString(usuarioExistente.get_nome_usuario()) &&
        senha == QString::fromStdString(usuarioExistente.get_senha_usuario())) {
        QMessageBox::information(this, "Login", "Login bem-sucedido!");
        accept();  // Fechar o diálogo
    } else {
        QMessageBox::warning(this, "Login", "Nome de usuário ou senha incorretos!");
    }
}

void LoginCadastroDialog::realizarCadastro() {
    QString nomeUsuario = nomeUsuarioLineEdit->text();
    QString senha = senhaLineEdit->text();

    // Lógica de cadastro
    // Exemplo simples: criar um novo usuário
    Usuario novoUsuario(nomeUsuario.toStdString(), "email", senha.toStdString(), 1, 25, 70.0, true);

    QMessageBox::information(this, "Cadastro", "Cadastro bem-sucedido!");
    accept();  // Fechar o diálogo
}
