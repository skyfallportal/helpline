#include <iostream> 
using namespace std;
struct node
{
    string name;
    node*a[10];
};
class book
{
    int n1, n2, n3, ch, chap, se, ss, i, j, k;
    node *temp = new node;

public:
    void
    add()
    {
        cout << "Enter the book name = ";
        cin >> temp -> name;
        gettree();
    }
    void gettree()
    {
        for (int i = 0; i < 2; i++)
        {
            temp->a[i] = new node;
            temp->a[i] -> name = "empty";
            for (int j = 0; j < 2; j++)
            {
                temp->a[i]->a[j] = new node;
                temp->a[i]->a[j] -> name = "empty";
                for (int k = 0; k < 2; k++)
                {
                    temp->a[i]->a[j]->a[k] = new node;
                    temp -> a[i]->a[j]->a[k]->name = "empty";
                }
            }
        }
    }
    void addchap()
    {
        cout << "Enter the chapters: ";
        // cin>>n1; cout<<endl;
        for (int i = 0; i < 2; i++)
        {
            cout << "chapter:-" << i + 1 << "=\t";
            cin >> temp -> a[i]->name;
        }
    }
    void addsec()
    {
        cout << "Enter the chapter no = ";
        cin >> chap;
        cout << endl;
        cout << "Enter the sections: ";
        // cin>>n2; cout<<endl; 
        for(int i = 0; i < 2; i++)
        {
            cout << "section:-" << i + 1 << "=\t";
            cin >> temp->a[chap - 1]->a[i]->name;
        }
    }
    void addsubs()
    {
        cout << "Enter chapter no = ";
        cin >> chap;
        cout << endl;
        cout << "Enter section no = ";
        cin >> ss;
        cout << endl;
        cout << "Enter the subsections:  "; 
            // cin>>n3;
            cout<< endl;
        for (int i = 0; i < 2; i++)
        {
            cout << "sub section :- " << i + 1 << "\t";
            cin >> temp -> a[chap - 1]->a[ss - 1]->a[i]->name;
            cout << endl;
        }
    }
    void display()
    {
        cout << "*******" << temp->name << "*******" << endl;
        for (int i = 0; i < 2; i++)
        {
            if (temp->a[i]->name != "empty")
            {
                cout << "\t" << i + 1;
                cout << " " << temp->a[i]->name << endl;
            }
            for (int j = 0; j < 2; j++)
            {
                if (temp->a[i]->a[j]->name != "empty")
                {
                    cout << "\t\t" << i + 1 << "." << j + 1;
                    cout << "  "<<temp->a[i]->a[j]->name<<endl; 
                }
                for (int k = 0; k < 2; k++)
                {
                    if (temp->a[i]->a[j]->a[k]->name != "empty")
                    {
                        cout << "\t\t\t" << i + 1 << "." << j + 1 << "." << k + 1;
                        cout << " 
                                "<<temp->a[i]->a[j]->a[k]->name<<endl; 
                    }
                }
            }
        }
    }
};
int main()
{
    book b;
    char ans;
    int ch;
    b.add();
    do
    {
        cout << " MENU " << endl < "1.Add chapter";
        cout << "\n2.Add section\n3.Add subsection\n4.Dispaly\n";
        cout << "Enter the choice = ";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            b.addchap();
            break;
        case 2:
            b.addsec();
            break;
        case 3:
            b.addsubs();
            break;
        case 4:
            b.display();
            break;
        default:
            cout << "WRONG CHOICE";
            break;
        }
        cout << "Do you want to continue ? (y/n)";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    return 0;
}