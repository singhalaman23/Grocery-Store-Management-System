// GROCERY STORE MANAGEMENT SYSTEM
// Username is "aman"
// Password is "123"
#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include<iomanip>   // header file to include manipulators
using namespace std;
void main_menu();

vector <string> finalCartNames;
vector <int> finalCartPrices;
vector <int> finalCartQuantity;

// function to store items in the cart
void cart(vector <string> ItemNames, vector<int> ItemPrice, vector <int> ItemQuantity){
    vector <string> cartNames;
    vector <int> cartPrice;
    vector <int> cartQuantity;
    int cartChoice;
    int quantity;
    cout<<"\nEnter the choice you want to add to your cart : ";
    cin>>cartChoice;
    cout<<"\nEnter the quantity of the chosen product : ";
    cin>>quantity;
    cartNames.push_back(ItemNames[cartChoice-1]);
    cartPrice.push_back(ItemPrice[cartChoice-1]);
    cartQuantity.push_back(ItemQuantity[cartChoice-1]+quantity);

    finalCartNames.push_back(ItemNames[cartChoice-1]);
    finalCartPrices.push_back(ItemPrice[cartChoice-1]);
    finalCartQuantity.push_back(ItemQuantity[cartChoice-1]+quantity);
    
    cout<<ItemNames[cartChoice-1]<<" of Rs "<<ItemPrice[cartChoice-1]<<"/- and quantity = "<<ItemQuantity[cartChoice-1]+quantity<<",has been added to cart !!!\n";

    cout<<"\n\nItems present in the cart are as follows :-\n\n";
    for(int i=0; i<finalCartNames.size(); i++){
        cout<<"{"<<i+1<<"}\t"<<finalCartNames[i]<<" \t:\t "<<finalCartPrices[i]<<"/-\tQuantity = "<<finalCartQuantity[i]<<endl;
    }

}
int Amount_to_pay = 0;    // global variable initializing the "NET AMOUNT PAYABLE" = 0
// function to display the final cart
void viewCart(){
    string choice;
    for (int i = 0; i < finalCartNames.size(); i++)
    {
        cout << "{" << i + 1 << "}\t" << finalCartNames[i] << " \t:\t " << finalCartPrices[i] << "/-\tQuantity = " << finalCartQuantity[i] << endl;
    }
    cout<<"Type (CONFIRM) to confirm the order and generate the bill, or press M to go back to main menu.\n";
    cin>>choice;
    if(choice == "M"){
        main_menu();
    }
    else if(choice == "CONFIRM"){
        cout<<"-------------------------------------------INVOICE--------------------------------------------------\n";
        cout << "S.No.\t\t\tName\t\t\tQuantity\tRate\t    Net price\n";
        cout<<"----------------------------------------------------------------------------------------------------\n";
        for(int i = 0; i<finalCartNames.size(); i++){
            cout<<"["<<i+1<<"]\t"<<setw(30)<<finalCartNames[i]<<"\t\t"<<finalCartQuantity[i]<<"\t\t"<<finalCartPrices[i]<<"\t\t"<<finalCartPrices[i]*finalCartQuantity[i]<<endl;
            Amount_to_pay = Amount_to_pay + finalCartPrices[i]*finalCartQuantity[i];
        }

    }
    else{
        cout<<"Wrong Input !!"<<endl;
    }
    
    cout<<"----------------------------------------------------------------------------------------------------\n";
    cout<<"NET AMOUNT PAYABLE : "<<Amount_to_pay<<"/-"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------\n";
}


class GroceryGeneralStore       // base class which stores all the basic informations of the shop
{
protected:
    string username = "aman";      //user shall enter only this username and password to get access to the software
    string password = "123";
    string nameOfShop = "Grocery General Store";    // name of the shop
    int established_year = 1982;
    int no_of_employees = 4;
    string location = "Main Road, Ranchi, Jharkhand";
    string GSTnum = "20AAUPD7122J1MP";
    string phone_num = "8507267494";        // this phone number is important if in case the user forgets the username and password
    string password_entered;
    string username_entered;

public:
    void input_login()
    {
        cout<<"\n\n\t\tLOGIN PAGE\t\t\n\n";
        
        cout << "Enter Username : ";
        cin >> username_entered;
        
        try
        {
            cout << "Enter Password : ";
            cin >> password_entered;
            if(password_entered  != password){
                throw password_entered;     // wrong password is thrown in the corresponding catch block

            }
        }
        catch(string ex)
        {
            int forgot_password_var;
            string phone_num_entered_FP;
            cout<<endl<<ex<<" is wrong password !"<<endl;
            cout<<"\nForgot password ?\nIf Yes, Press 1. If NO, Press 0 : ";
            cin>>forgot_password_var;
            if(forgot_password_var == 1){
                cout<<"Enter your phone number : ";
                cin>>phone_num_entered_FP;
                if(phone_num_entered_FP == phone_num){
                    cout<<"\nThe password is : "<<password<<endl;
                }
                else{
                    cout<<"Wrong Phone Number !"<<endl;
                }
            }

        }
        
    }
    int output_login()
    {
        while (username != username_entered || password != password_entered)
        {
            cout << "Try again !" << endl<< endl;
            input_login();
        }
        return 1;
    }
};
class EmployeeDetails       // Class to display the names of employees
{
public:
    void display()
    {
        char choice;
        string st;
        ifstream in("amity_oop_project_GSMS_employee_details.txt");     // this opens the file using constructor
        while (in.eof() == 0)
        {
            in >> st;
            cout << st << endl;
        }
        cout<<"Press M to go back to main menu : ";
        cin>>choice;
        if(choice == 'M'){
            main_menu();
        }
    }
};
class AllProducts       // class to store and display all the items available in the shop
{
    protected:
    int choice1;
    char choice2;

public:
    void display_AllProductsNames()
    {
        vector <string> AllProductsNames {"(1)Chocolates","(2)Breads","(3)Ketchups","(4)Noodles and soups","(5)Soap and detergent","(6)Dry fruits","(7)Cooking oils","(8)Rice and Sugar","(9)Softdrinks","(10)Ice-cream"};
        for(int i=0;i<AllProductsNames.size();i++)
        {
            cout<<AllProductsNames[i]<<endl;
        }
    }
    void input_AllProductsChoice()
    {
        cout << "\nEnter your choice : ";
        cin >> choice1;
        switch (choice1)
        {
        case 1:
        {
            vector <string> chocolateNames {"(1)Dark chocolate","(2)Belgian chocolate","(3)Fruit & nut chocolate","(4)Plane chocolate"};
            vector <int> chocolatePrice {100,250,95,80};
            vector <int> chocolateQuantity {0,0,0,0};       // this initializes the quantity of all the chocolates as 0

            for(int i=0; i<chocolateNames.size(); i++){
                cout<<chocolateNames[i]<<" : "<<chocolatePrice[i]<<"/-\n";
            }

            cart(chocolateNames,chocolatePrice,chocolateQuantity);      // this calls the cart function
            cout << "\nPress M to go back to main menu or Press P to go back to previous menu\n";
            cin >> choice2;
            if (choice2 == 'M')
            {
                main_menu();
            }
            else if (choice2 == 'P')
            {
                display_AllProductsNames();
                input_AllProductsChoice();
            }

            break;
        }
        case 2:
        {
            vector <string> BreadNames {"(1)Small Bread","(2)Large Bread","(3)Brown Bread"};
            vector <int> BreadPrice {18,35,40};
            vector <int> BreadQuantity {0,0,0};

            for(int i=0; i<BreadNames.size(); i++){
                cout<<BreadNames[i]<<" : "<<BreadPrice[i]<<"/-\n";
            }

            cart(BreadNames,BreadPrice,BreadQuantity);
    
            cout << "\nPress M to go back to main menu or Press P to go back to previous menu\n";
            cin >> choice2;
            if (choice2 == 'M')
            {
                main_menu();
            }
            else if (choice2 == 'P')
            {
                display_AllProductsNames();
                input_AllProductsChoice();
            }
            break;
        }
        case 3:
        {
            vector <string> KetchupsNames {"(1)Tomato ketchup","(2)Green chilli ketchup","(3)Red chilli ketchup"};
            vector <int> KetchupsPrice {20,20,25};
            vector <int> KetchupQuantity {0,0,0};

            for(int i=0; i<KetchupsNames.size(); i++){
                cout<<KetchupsNames[i]<<" : "<<KetchupsPrice[i]<<"/-\n";
            }

            cart(KetchupsNames,KetchupsPrice,KetchupQuantity);

            cout << "\nPress M to go back to main menu or Press P to go back to previous menu\n";
            cin >> choice2;
            if (choice2 == 'M')
            {
                main_menu();
            }
            else if (choice2 == 'P')
            {
                display_AllProductsNames();
                input_AllProductsChoice();
            }
            break;
        }
        case 4:
        {
            vector <string> Noodles_and_soupsNames {"(1)Chowmein","(2)Chinese Noodles","(3)Manchao noodles","(4)Tomato soup","(5)Manchao soup"};
            vector <int> Noodles_and_soupsPrice {35,45,45,10,10};
            vector <int> Noodles_and_soupsQuantity {0,0,0,0,0};

            for(int i=0; i<Noodles_and_soupsNames.size(); i++){
                cout<<Noodles_and_soupsNames[i]<<" : "<<Noodles_and_soupsPrice[i]<<"/-\n";
            }

            cart(Noodles_and_soupsNames,Noodles_and_soupsPrice,Noodles_and_soupsQuantity);

            cout << "\nPress M to go back to main menu or Press P to go back to previous menu\n";
            cin >> choice2;
            if (choice2 == 'M')
            {
                main_menu();
            }
            else if (choice2 == 'P')
            {
                display_AllProductsNames();
                input_AllProductsChoice();
            }
            break;
        }
        case 5:
        {
            vector <string> Soap_and_detergentNames {"(1)Soap","(2)Detergent 1/2 kg","(3)Detergent 1 kg"};
            vector <int> Soap_and_detergentPrice {10,25,50};
            vector <int> Soap_and_detergentQuantity {0,0,0};

            for(int i=0; i<Soap_and_detergentNames.size(); i++){
                cout<<Soap_and_detergentNames[i]<<" : "<<Soap_and_detergentPrice[i]<<"/-\n";
            }

            cart(Soap_and_detergentNames,Soap_and_detergentPrice,Soap_and_detergentQuantity);

            cout << "\nPress M to go back to main menu or Press P to go back to previous menu\n";
            cin >> choice2;
            if (choice2 == 'M')
            {
                main_menu();
            }
            else if (choice2 == 'P')
            {
                display_AllProductsNames();
                input_AllProductsChoice();
            }
            break;
        }
        case 6:
        {
            vector <string> DryFruitsNames {"(1)Almond 250g","(2)Apricot 250g","(3)Cashew nuts 250g","(4)Pistachio 250g","(5)Raisin 250g"};
            vector <int> DryFruitsPrice {250,315,115,200,90};
            vector <int> DryFruitsQuantity {0,0,0,0,0};

            for(int i=0; i<DryFruitsNames.size(); i++){
                cout<<DryFruitsNames[i]<<" : "<<DryFruitsPrice[i]<<"/-\n";
            }

            cart(DryFruitsNames,DryFruitsPrice,DryFruitsQuantity);

            cout << "\nPress M to go back to main menu or Press P to go back to previous menu\n";
            cin >> choice2;
            if (choice2 == 'M')
            {
                main_menu();
            }
            else if (choice2 == 'P')
            {
                display_AllProductsNames();
                input_AllProductsChoice();
            }
            break;
        }
        case 7:
        {
            vector <string> CookingOilsNames {"(1)Mustard Oil 1L","(2)Refined Oil 1L","(3)Sunflower Oil 1L","(4)Rice Bran Oil 1L"};
            vector <int> CookingOilsPrice {200,155,215,220};
            vector <int> CookingOilsQuantity {0,0,0,0};

            for(int i=0; i<CookingOilsNames.size(); i++){
                cout<<CookingOilsNames[i]<<" : "<<CookingOilsPrice[i]<<"/-\n";
            }

            cart(CookingOilsNames,CookingOilsPrice,CookingOilsQuantity);

            cout << "\nPress M to go back to main menu or Press P to go back to previous menu\n";
            cin >> choice2;
            if (choice2 == 'M')
            {
                main_menu();
            }
            else if (choice2 == 'P')
            {
                display_AllProductsNames();
                input_AllProductsChoice();
            }
            break;
        }
        case 8:
        {
            vector <string> Rice_and_sugarNames {"(1)Brown Rice 1kg","(2)White Rice 1kg","(3)Basmati Rice 1kg","(4)Biryani Rice 1kg","(5)Long grain rice 1kg","(6)Sugar 1kg"};
            vector <int> Rice_and_sugarPrice {105,80,145,95,75,45};
            vector <int> Rice_and_sugarQuantity {0,0,0,0,0,0};

            for(int i=0; i<Rice_and_sugarNames.size(); i++){
                cout<<Rice_and_sugarNames[i]<<" : "<<Rice_and_sugarPrice[i]<<"/-\n";
            }

            cart(Rice_and_sugarNames,Rice_and_sugarPrice,Rice_and_sugarQuantity);

            cout << "\nPress M to go back to main menu or Press P to go back to previous menu\n";
            cin >> choice2;
            if (choice2 == 'M')
            {
                main_menu();
            }
            else if (choice2 == 'P')
            {
                display_AllProductsNames();
                input_AllProductsChoice();
            }
            break;
        }
        case 9:
        {
            vector <string> SoftDrinksNames {"(1)Chocolate Milkshake","(2)Vanilla Milkshake","(3)Strawberry Milkshake","(4)Coke","(5)Energy Drink","(6)Cold Coffee"};
            vector <int> SoftDrinksPrice {45,45,45,35,75,55};
            vector <int> SoftDrinksQuantity {0,0,0,0,0,0};

            for(int i=0; i<SoftDrinksNames.size(); i++){
                cout<<SoftDrinksNames[i]<<" : "<<SoftDrinksPrice[i]<<"/-\n";
            }

            cart(SoftDrinksNames,SoftDrinksPrice,SoftDrinksQuantity);

            cout << "\nPress M to go back to main menu or Press P to go back to previous menu\n";
            cin >> choice2;
            if (choice2 == 'M')
            {
                main_menu();
            }
            else if (choice2 == 'P')
            {
                display_AllProductsNames();
                input_AllProductsChoice();
            }
            break;
        }
        case 10:
        {
            vector <string> IceCreamsNames {"(1)Chocolate Icecream","(2)Vanilla Icecream","(3)Strawberry Icecream","(4)Two in One Icecream","(5)Orange stick Icecream","(6)Choco chip Icecream","(7)Butter Scotch Icecream"};
            vector <int> IceCreamsPrice {30,30,30,35,10,45,35};
            vector <int> IceCreamsQuantity {0,0,0,0,0,0,0};

            for(int i=0; i<IceCreamsNames.size(); i++){
                cout<<IceCreamsNames[i]<<" : "<<IceCreamsPrice[i]<<"/-\n";
            }

            cart(IceCreamsNames,IceCreamsPrice,IceCreamsQuantity);

            cout << "\nPress M to go back to main menu or Press P to go back to previous menu\n";
            cin >> choice2;
            if (choice2 == 'M')
            {
                main_menu();
            }
            else if (choice2 == 'P')
            {
                display_AllProductsNames();
                input_AllProductsChoice();
            }
            break;
        }
        default:
            cout << "Wrong Choice !!! \n";
            cout << "\nPress M to go back to main menu or Press P to go back to previous menu\n";
            cin >> choice2;
            if (choice2 == 'M')
            {
                main_menu();
            }
            else if (choice2 == 'P')
            {
                display_AllProductsNames();
                input_AllProductsChoice();
            }
            break;
        }
    }
};
// this is the customer care class which is publicly inherited from the GroceryGeneralStore class
class CustomerCare : public GroceryGeneralStore{
    int customer_care_variable;
    string entered_phone_num;
    public:
    void input()
    {
        cout<<"Hi, you are now chatting with customer care agent.\n";
        cout<<"Please choose from below options :-\n";
        cout<<"(1)I cannot login\n(2)I cannot place orders\n(3)I cannot generate bills\n(4)My problem is not listed\n";
        cout << "\nEnter your choice : ";
        cin>>customer_care_variable;

        switch (customer_care_variable)
        {
            case 1:     // this will help in the recovery of registered username and password by using the phone number
            {
            cout<<"Enter your phone number : ";
            cin>>entered_phone_num;
            if (entered_phone_num == phone_num){
                char k;
                cout<<"\nPhone number entered is correct !!!\n\n";
                cout<<"Your Login Credentials are :-\n";
                cout<<"Username = ( "<<username<<" )\n";
                cout<<"Password = ( "<<password<<" )\n\n";
                cout<<"Press M to go back to main menu : ";
                cin>>k;
                if(k == 'M'){
                    main_menu();
                }

            }
            else{
                cout<<"\nWrong phone number entered !!! Please try again.\n";
                input();
            }
            break;
            }
            case 2:
            {
                char k;
                cout<<"\nIf you are unable to place any order, then go back to main menu and choose 1st option.\n";
                cout<<"Press M to go back to main menu : ";
                cin>>k;
                if(k == 'M'){
                    main_menu();
                }

            }
            case 3:
            {
                char k;
                cout<<"If you are unable to generate bills, first add items to your cart and then go back to main menu and choose 2nd option.\n";
                cout<<"Press M to go back to main menu : ";
                cin>>k;
                if(k == 'M'){
                    main_menu();
                }


            }
            case 4:     // this will help the user to register a written complain regarding the software
            {
                char m;
                char k;
                cout<<"If your problem is not listed here, you can write to us and we will get back to you as soon as possible.\n";
                cout<<"NOTE : Your messeges will be saved to us in the (Consumer complains) file. Just open the file to see your complains.\n\n";
                cout<<"\nIf you want to write to us, press W.\n";
                cout<<"If you want to give us a call, press C.\n";
                cout<<"Enter your choice : ";
                cin>>m;
                if(m == 'W')
                {
                    string complain_string;
                    ofstream out("Consumer_complains_file_GSMS.txt");       // complain typed will be saved in this file
                    cout<<"Type your complain here :- (Type (END) to complete the complain) \n\n";
                    while (out){
                        getline(cin,complain_string);
                        if(complain_string == "END")
                        {
                            break;
                        }
                        out<<complain_string<<endl;
                    }
                    out.close();
                    cout<<"\nThankyou ! We will get back to you soon.\n";
                    cout<<"Press M to go back to main menu : ";
                    cin>>k;
                    if(k == 'M'){
                        main_menu();
                    }

                }
                else if(m == 'C'){
                    cout<<"\nOur phone number is : 1800 84 2500. Just give us a missed call and we will get back to you.\nThankyou !"<<endl;
                    cout<<"Press M to go back to main menu : ";
                    cin>>k;
                    if(k == 'M'){
                        main_menu();
                    }
                }
            }
            
            default:
            {
                cout<<"Wrong Input !!!\n";
                break;
            }
        }

    }

};
//this class stores the details of the bank accounts used by the shop
class ManageBankAccounts{

    public:
    void displayBank1()
    {
        char k;
        string BankName1 = "Axis bank";
        string Bank1AccountNo = "75000023644412";
        string Bank1IFSCCode = "AXB12540";
        string Bank1Branch = "Main Road";
        cout<<"Your bank account details are as follows:-\n\n";
        cout<<"Bank Name : "<<BankName1<<endl;
        cout<<"Bank Account Number : "<<Bank1AccountNo<<endl;
        cout<<"Bank IFSC code : "<<Bank1IFSCCode<<endl;
        cout<<"Bank branch name : "<<Bank1Branch<<endl<<endl;
        cout<<"Press M to go back to main menu : ";
        cin>>k;
        if(k == 'M')
        {
            main_menu();
        }
        else{
            cout<<"Wrong input !!!"<<endl;
        }
    }
    void displayBank2()
    {
        char k;
        string BankName2 = "City Bank";
        string Bank2AccountNo = "67000023685002";
        string Bank2IFSCCode = "CBI12790";
        string Bank2Branch = "Church road";
        
        cout<<"Your bank account details are as follows:-\n\n";
        cout<<"Bank Name : "<<BankName2<<endl;
        cout<<"Bank Account Number : "<<Bank2AccountNo<<endl;
        cout<<"Bank IFSC code : "<<Bank2IFSCCode<<endl;
        cout<<"Bank branch name : "<<Bank2Branch<<endl<<endl;
        cout<<"Press M to go back to main menu : ";
        cin>>k;
        if(k == 'M')
        {
            main_menu();
        }
        else{
            cout<<"Wrong input !!!"<<endl;
        }
    }

};
// this class just diplays the basic details of the shop. It is inherited from the class GroceryGeneralStore
class AboutUs : public GroceryGeneralStore{
    public:
    void display(){
        cout<<"All details of your shop are as follows :-\n\n";
        cout<<"Name of the shop : "<<nameOfShop<<endl;
        cout<<"Establishment year : "<<established_year<<endl;
        cout<<"No of Employees curently working : "<<no_of_employees<<endl;
        cout<<"GSTIN NO : "<<GSTnum<<endl;
        cout<<"Address : "<<location<<endl;

    }

};
void main_menu()        // this function is the main menu of the software
{
    int main_menu_var;
    
    // cout<<"\nMAIN MENU\n";
    cout << "\n\t\t\tGROCERY STORE MANAGEMENT SYSTEM\t\t\t\n\n\n\n";
    cout << "(1)Place an order\n(2)Generate the bill\n(3)Show all Employee details\n(4)Chat with customer care agent\n(5)Manage bank accounts\n(6)About the shop\n(7)Log Out\n";
    cout << "\nEnter your choice : ";
    cin >> main_menu_var;

    switch (main_menu_var)
    {
        case 1:
        {
            AllProducts a1;
            a1.display_AllProductsNames();
            a1.input_AllProductsChoice();
            break;
        }
        case 2:
        {
            if(finalCartNames.size() == 0){
                cout<<"Cart is Empty, Please place an order to generate a bill !"<<endl;
            }
            else{
                cout<<"Items present in your cart are as follows :-"<<endl;
                viewCart();

            }
            break;
        }
        case 3:
        {
            EmployeeDetails e1;
            e1.display();
            // main_menu();
            break;
        }
        case 4:
        {
            CustomerCare c1;
            c1.input();
        }
        case 5:
        {
            int k;
            ManageBankAccounts b1;
            cout<<"You have 2 Bank accounts :-\n";
            cout<<"(1)Axis Bank account\n";
            cout<<"(2)City Bank account\n\n";
            cout<<"Enter your choice : ";
            cin>>k;
            if(k==1){
                b1.displayBank1();
            }
            else if(k==2){
                b1.displayBank2();
            }
            else{
                cout<<"Wrong choice !!!"<<endl;
                cout<<"Redirecting you to main menu...."<<endl;
                main_menu();
            }

        }
        case 6:
        {
            char k;
            AboutUs a1;
            a1.display();
            cout<<"Press M to go back to main menu : ";
            cin>>k;
            if(k == 'M'){
                main_menu();
            }
            else{
                cout<<"Wrong input !!!"<<endl;
                cout<<"Redirecting you to main menu...\n";
                main_menu();
            }
        }
        case 7:
        {
            string choice;
            cout<<"\nAre you sure you want to log out and exit the program ?\nType either (YES) or (NO) : ";
            cin>>choice;
            if(choice == "YES"){
                cout<<"Logging Out...\n";
                exit(0);
            }
            else if(choice == "NO"){
                main_menu();
            }
            else{
                cout<<"Wrong Input !!!\n";
            }
        }

        default:
        {
            cout<<"Wrong input !!!\n";
            break;
        }
    }

}

int main()
{
    GroceryGeneralStore L;
    L.input_login();
    int login_var = L.output_login();
    if (login_var == 1)
    {
        cout << "\nRunning...\n";
    }
    main_menu();

    return 0;
}
