//21120408 - Dang Tuan Anh

#include<iostream>
using namespace std;
#include<vector>

struct Node{
    int data;
    Node* next = NULL;
};

//tạo ra một node mới
Node* makeNode(int data){
    Node* NewNode = new Node;
    NewNode->data = data;
    NewNode->next = NULL;
    return NewNode;
}

//lấy node cuối cùng trong danh sách
Node* GetLast(Node* root){
    if(root == NULL) return NULL;
    while(root->next != NULL){
        root = root->next;
    }
    return root;
}

//thêm vào cuối danh sách
void AddLast(Node* &root, int data){
    Node* newNode = makeNode(data);
    if(root == NULL){
        root = newNode;
    }
    else{
        Node* NodeLast = GetLast(root);
        NodeLast->next = newNode;
    }
}

//thêm vào đâu danh sách
void AddFirst(Node* &root, int data){
    Node* newNode = makeNode(data);
    newNode->next = root;
    root = newNode;
}

//them node vao giữa danh sách tại index 
void AddMiddle(Node* &root, int index, int data){
    if(index <= 1){
        AddFirst(root, data);
        return;
    }
    int i = 2;
    Node* tem = root;
    while(tem->next != NULL && i != index){
        tem = tem->next;
        i++;
    }
    Node* newNode = makeNode(data);
    newNode->next = tem->next;
    tem->next = newNode;
}

//đếm số lượng node có trong danh sách
int CountNode(Node* root){
    if(root == NULL) return 0;
    return 1 + CountNode(root->next);
}

//thêm sau giá trị x
void Themgiua(Node* root, int data, int x){
    while(root->data != x && root->next != NULL){
        root = root->next;
    }
    Node* tem = makeNode(data);
    tem->next = root->next;
    root->next = tem;
}

//sắp xếp data trong danh sách liên kết
void SortNode(Node* root){
    if(root == NULL || root->next == NULL) return;
    Node* tem = NULL;
    while(root->next != NULL){
        tem = root->next;
        while(tem != NULL){
            if(root->data > tem->data){
                swap(root->data, tem->data);
            }
            tem = tem->next;
        }
        root = root->next;
    }
}

//reverse
void ReverseNode(Node* &root){
    if(root == NULL) return;
    Node* x = root->next;
    Node* tem = root;
    tem->next = NULL;
    Node* tem1 = NULL;
    while(x != NULL){
        tem1 = x->next;
        x->next = tem;
        tem = x;
        x = tem1;
    }
    root = tem;
}

//hiển thị data trong danh sách liên kết
void showNode(Node* root){
    if(root == NULL){
        cout << "danh sach trong\n";
        return;
    }
    while(root != NULL){
        cout << root->data << " ";
        root = root->next;
    }
}

void inyeucau(Node* root){

    if(root->data > root->next->data){
        cout << root->data << " ";
    }
    int tem = root->data;
    root = root->next;
    
    while(root->next != NULL){
        if(root->data > tem && root->data > root->next->data){
            cout << root->data << " ";
        }
        tem = root->data;
        root = root->next;
    }
    if(root->data > tem){
        cout << root->data << endl;
    }
}

void Bai_cuoi(Node* root1){
    Node* root = root1;
    while(root != NULL){
        int tem = root->data;
        Node* x = root->next;
        while(x != NULL){
            if(tem < x->data){
                tem = x->data;
                break;
            }
            x = x->next;
        }
        root->data = tem;
        root = root->next;
    }
    cout << endl;
    showNode(root1);
}

void xoadau(Node* &root){
    if(root == NULL){return;}
    Node* tem = root->next;
    delete root;
    root = tem;
}

void xoacuoi(Node* &root){
    if(root == NULL) return;
    if(root->next == NULL){
        delete root;
        root = NULL;
        return;
    }
    Node* tem = root->next;
    Node* tem1 = root;
    while(tem->next != NULL){
        tem1 = tem;
        tem = tem->next;
    }
    delete tem;
    tem1->next = NULL;
}

void xoagiua(Node* &root){
    int count = 0;
    Node* tem = root;
    while(tem != NULL){
        tem = tem->next;
        count++;
    }
    if(count == 1 || count == 2){
        root= NULL;
        return;
    }
    tem = root;
    if(count % 2 == 0){
        int i = 1;
        while(tem != NULL && i != count/2 - 1){
            tem = tem->next;
            i++;
        }
        Node* tem1 = tem->next;
        Node* tem2 = tem->next->next;
        tem ->next = tem->next->next->next;
        delete tem1;
        delete tem2;
    }
    else{

        int i = 0;
        while(tem != NULL && i != count/2-1){
            tem = tem->next;
            i++;
        }
        Node* tem1 = tem->next;
        tem->next = tem->next->next;
        delete tem1;
    }
    
}

void yeucau1(Node* root1, int k){
    Node* root = NULL;
    while(root1 != NULL){
        AddLast(root, root1->data);
        root1 = root1->next;
    }
    // cout << endl;
    // showNode(root);
    Node* tem = root;
    while(tem != NULL){
        int dem = 0;
        Node* t = tem->next;
        while(t != NULL){
            dem++;
            t = t->next;
        }
        if(dem < k) break;
        int count = 0;
        int s = 0;
        Node* tem1 = tem->next;
        while(tem1 != NULL && count != k){
            if(tem->data <= tem1->data){
                break;
            }
            s += tem1->data;
            count++;
            tem1 = tem1->next;
        }
        if(count == k) tem->data += s;
        tem = tem->next;
    }
    cout << endl;
    showNode(root);
}

void yeucau2(Node* root, int k){
    int max = -999999999, tem = 0;
    while(root != NULL){
        int dem = 0;
        Node* t = root;
        while(t != NULL){
            dem++;
            t = t->next;
        }
        if(dem < k) break;
        int s = 0;
        Node* tem1 = root;
        dem = 0;
        while(tem1 != NULL && dem != k){
            s+= tem1->data;
            tem1 = tem1->next;
            dem++;
        }
        if(s > max ) max = s;
        root = root->next;
    }
    cout << max;
}

vector<int> ran;

void cuoi1(Node* root1, int* a, int m){
    Node* root = root1;
    vector<int> v;
    cout << "yeu cau 1: \n";
    for(int i = 0; i < m; i++){
        int check = 0;
        root = root1;
        while(root != NULL){
            if(a[i] == root->data){
                check = 1;
                break;
            }
            root = root->next;
        }
        if(check == 0){
            v.push_back(a[i]);
        }
    }
    for(auto it : v) cout << it << " ";
    cout << endl;
    for(auto it : v){
        AddLast(root1, it);
    }
    cout << "yeu cau 2:" << endl;
    cout << "danh sach sau khi them \n";
    
    cout << endl;
        int x = CountNode(root1);
        if(x >= m){
            a = new int[x];
            root = root1;
            for(int i = 0; i < x; i++){
                a[i] = root->data;
                root  = root->next;
            }
            showNode(root1);
            cout << "maang sau khi them\n";
    for(int i = 0; i < m; i++){
        cout << a[i] << " ";}
        }
        else{
            Node* tem = NULL;
            for(int i = 0; i < m; i++){
                AddLast(tem, a[i]);
            }
            showNode(tem);
            cout << endl;
            cout << "maang sau khi them\n";
    for(int i = 0; i < m; i++){
        cout << a[i] << " ";}
        }

}

int main(){
    Node* root = NULL;
    int i = 4;
    cout << "nhap so luong pt mang: ";
    int m;
    cin >> m;
    cout << "nhap phan tu cua mang: \n";
    int* a = new int[m];
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        ran.push_back(a[i]);
    }
    int n; cout << "nhap so luong danh sach n: "; cin >> n;
    cout << "nhap phan tu danh sach :\n";
    while(n--){
        int x;
        cin >> x;
        AddLast(root, x);
    }
    cuoi1(root, a, m);
    system("pause");
}