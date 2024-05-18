#include <iostream>
using namespace std;

struct node
{
    string name;
    double value;
    double weight;
    node *left;
    node *right;
};

node *A = NULL;

node *sukurtiPreke(string value1, double value2, double value3);
node *pridetiPreke(node *root, string value1, double value2, double value3);
void valueMaker();
void spausdintiPrekes(node *root);
void pasirinkimas();
void istrintiVisasPrekes(node *root);
void spausdinitPrekePavadinimu(node *preke, string pavadinimas);
void valueMaker2();
void spausdintiPrekeKaina(node *preke);
void spausdintiBrangesnesUz(node *root, int number);
void valueMaker3();
void spausdintiPigesnesUz(node *root, int number);
void valueMaker4();
void istrintiPreke();
void istrintiPigiausiaPreke(node *root);
void istrintiBrangiausiaPreke(node *root);
void trinamosPrekesPasirinkimas();
node *pasirinktosPrekesTrinimas(node *root, string pasirinkimas);
node *rastiMaziausiaNode(node *preke);

int main()
{

    pasirinkimas();
    return 0;
}

void pasirinkimas()
{
    while (true)
    {
        int pasirinkimas;
        cout << "1 - Prideti preke" << endl;
        cout << "2 - Parodyti visas prekes" << endl;
        cout << "3 - Istrinti visas prekes" << endl;
        cout << "4 - Parodyti preke pagal pavadinima" << endl;
        cout << "5 - Parodyti preke pagal kaina" << endl;
        cout << "6 - rodyti prekes brangesnes uz pasirinkta kaina" << endl;
        cout << "7 - rodyti prekes pigesnes uz pasirinkta kaina" << endl;
        cout << "8 - prekiu trinimas" << endl;
        cout << "99 - Iseiti is programos" << endl;
        cin >> pasirinkimas;

        switch (pasirinkimas)
        {
        case 1:
            valueMaker();
            break;
        case 2:
            spausdintiPrekes(A);
            break;
        case 3:
            istrintiVisasPrekes(A);
            A = NULL;
            cout << "Visos prekes istrintos!" << endl;
            break;
        case 4:
            valueMaker2();
            break;
        case 5:
            spausdintiPrekeKaina(A);
            break;
        case 6:
            valueMaker3();
            break;
        case 7:
            valueMaker4();
            break;
        case 8:
            istrintiPreke();
            break;
        case 99:
            return;
        }
    }
}

node *sukurtiPreke(string value1, double value2, double value3)
{

    node *newNode = new node();
    newNode->name = value1;
    newNode->value = value2;
    newNode->weight = value3;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *pridetiPreke(node *root, string value1, double value2, double value3)
{
    // jei nera prekes, prideti
    if (root == NULL)
    {
        return sukurtiPreke(value1, value2, value3);
    }
    if (value2 < root->value)
    { // jei esancios prekes kaina didesne uz pridedamos prekes kaina paeiti i kaire
        root->left = pridetiPreke(root->left, value1, value2, value3);
    }
    else if (value2 > root->value)
    { // jei esancios prekes kaina mazesne uz pridedamos prekes kaina paeiti i desine
        root->right = pridetiPreke(root->right, value1, value2, value3);
    }
    return root;
}

void valueMaker()
{
    string pavadinimas;
    double kaina;
    double svoris;

    cout << "Pavadinimas:" << endl;
    cin >> pavadinimas;
    cout << "Kaina:" << endl;
    cin >> kaina;
    cout << "Svoris:" << endl;
    cin >> svoris;
    A = pridetiPreke(A, pavadinimas, kaina, svoris);
}

void spausdintiPrekes(node *root)
{
    if (root == NULL)
    {
        return;
    }
    spausdintiPrekes(root->left);
    cout << "Preke: " << root->name << endl;
    cout << "Kaina: " << root->value << "eur" << endl;
    cout << "Svoris: " << root->weight << "kg" << endl;
    cout << "-----------------" << endl;
    spausdintiPrekes(root->right);
}

void istrintiVisasPrekes(node *root)
{
    if (root == NULL)
    {
        return;
    }

    // rekursiviai istrinti prekes
    istrintiVisasPrekes(root->left);
    istrintiVisasPrekes(root->right);

    // istrinti dabartine preke
    delete root;
}

void valueMaker2()
{
    string pavadinimas;
    cout << "Kokia preke norite rasti?" << endl;
    cin >> pavadinimas;
    spausdinitPrekePavadinimu(A, pavadinimas);
}

void spausdinitPrekePavadinimu(node *preke, string pavadinimas)
{
    if (preke == NULL)
    {
        return;
    }

    if (preke->name == pavadinimas)
    {
        cout << "______________" << endl;
        cout << "Preke: " << preke->name << endl;
        cout << "Kaina: " << preke->value << "eur" << endl;
        cout << "Svoris:" << preke->weight << "kg" << endl;
        cout << "______________" << endl;
        return;
    }

    spausdinitPrekePavadinimu(preke->left, pavadinimas);
    spausdinitPrekePavadinimu(preke->right, pavadinimas);
}

void spausdintiPrekeKaina(node *preke)
{
    double number;
    cout << "Iveskite prekes, kuria norite rasti, kaina" << endl;
    cin >> number;

    while (preke != NULL)
    {
        if (preke->value == number)
        {
            cout << "______________" << endl;
            cout << "Preke: " << preke->name << endl;
            cout << "Kaina: " << preke->value << "eur" << endl;
            cout << "Svoris: " << preke->weight << "kg" << endl;
            cout << "______________" << endl;
            return;
        }
        else if (number < preke->value)
        {
            preke = preke->left;
        }
        else
        {
            preke = preke->right;
        }
    }
    cout << "tokios prekes nera!" << endl;
}
// helper funciton
void valueMaker3()
{
    int kaina;
    cout << "nuo kurios kainos rodyti prekes:" << endl;
    cin >> kaina;
    spausdintiBrangesnesUz(A, kaina);
}

void spausdintiBrangesnesUz(node *root, int number)
{
    if (root == NULL)
    {
        return;
    }
    spausdintiBrangesnesUz(root->left, number);

    if (root->value >= number)
    {
        cout << "______________" << endl;
        cout << " Preke: " << root->name << endl;
        cout << "Kaina: " << root->value << "eur" << endl;
        cout << "Svoris: " << root->weight << "kg" << endl;
        cout << "______________" << endl;
    }
    spausdintiBrangesnesUz(root->right, number);
}

void valueMaker4()
{
    int kaina;
    cout << "iki kurios kainos rodyti prekes:" << endl;
    cin >> kaina;
    spausdintiPigesnesUz(A, kaina);
}

void spausdintiPigesnesUz(node *root, int number)
{
    if (root == NULL)
    {
        return;
    }
    spausdintiPigesnesUz(root->left, number);

    if (root->value <= number)
    {
        cout << "______________" << endl;
        cout << "Preke: " << root->name << endl;
        cout << "Kaina: " << root->value << "eur" << endl;
        cout << "Svoris: " << root->weight << "kg" << endl;
        cout << "______________" << endl;
    }
    spausdintiPigesnesUz(root->right, number);
}

void istrintiPreke()
{
    cout << "1 - Istrinti pigiausia preke" << endl;
    cout << "2 - Istrinti brangiausia preke" << endl;
    cout << "3 - Istrinti pasirinkta preke" << endl;

    int pasirinkimas;
    cin >> pasirinkimas;

    switch (pasirinkimas)
    {
    case 1:
        istrintiPigiausiaPreke(A);
        break;
    case 2:
        istrintiBrangiausiaPreke(A);
        break;
    case 3:
        trinamosPrekesPasirinkimas();
        cout << "Pasirinkta preke istrinta!" << endl;
        break;
    }
}

void istrintiPigiausiaPreke(node *root)
{
    if (root == NULL)
    {
        return;
    }

    node *parent = NULL;
    while (root->left != NULL)
    {
        parent = root;
        root = root->left;
    }

    if (parent == NULL)
    {
        A = root->right;
    }
    else
    {
        parent->left = root->right;
    }

    delete root;
    cout << "pigiausia preke buvo istrinta!" << endl;
}

void istrintiBrangiausiaPreke(node *root)
{
    if (root == NULL)
    {
        return;
    }

    node *parent = NULL;
    while (root->right != NULL)
    {
        parent = root;
        root = root->right;
    }

    if (parent == NULL)
    {
        A = root->left;
    }
    else
    {
        parent->right = root->left;
    }

    delete root;
    cout << "brangiausia preke buvo istrinta!" << endl;
}

void trinamosPrekesPasirinkimas()
{
    string pasirinkimas;
    cout << "Irasykite pavadinima prekes kuria norite istrinti:" << endl;
    cin >> pasirinkimas;
    pasirinktosPrekesTrinimas(A, pasirinkimas);
}

node *pasirinktosPrekesTrinimas(node *root, string pasirinkimas)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (pasirinkimas != root->name)
    {
        root->left = pasirinktosPrekesTrinimas(root->left, pasirinkimas);
        root->right = pasirinktosPrekesTrinimas(root->right, pasirinkimas);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        node *temp = rastiMaziausiaNode(root->right);
        root->name = temp->name;
        root->value = temp->value;
        root->weight = temp->weight;
        root->right = pasirinktosPrekesTrinimas(root->right, temp->name);
    }
    return root;
}

node *rastiMaziausiaNode(node *preke)
{
    while (preke->left != NULL)
    {
        preke = preke->left;
    }
    return preke;
}// Temporary comment
