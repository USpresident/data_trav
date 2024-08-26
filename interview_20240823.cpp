#include <iostream>
struct Node {
    int val;
    Node *next;
    Node() {}
    Node(int v) : val(v), next(nullptr) {}
};

class Link{
private:
    Node *m_head;

public:

    void insert(int val)
    {
        if (m_head == nullptr) {
            m_head = new Node(val);
            return;
        }

        Node *temp = m_head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = new Node(val);
    }

    void delNode(int val)
    {
        if (m_head == nullptr) {
            return;
        }

        Node *rmNode = nullptr;
        if (m_head->val == val) {
            rmNode = m_head;
            m_head = m_head->next;
            delete rmNode;
            rmNode = nullptr;
            return;
        }

        Node *temp = m_head;
        while ((temp->next != nullptr) && (temp->next->val != val)) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            return;
        }

        rmNode = temp->next;
        temp->next = temp->next->next;
        delete rmNode;
    }

    Node *find(int val)
    {
        if (m_head == nullptr) {
            return nullptr;
        }

        Node *temp = m_head;
        while ((temp != nullptr) && (temp->val != val)) {
            temp = temp->next;
        }

        return temp;
    }

    void printlink()
    {
        Node *temp = m_head;
        while (temp != nullptr) {
            std::cout << temp->val << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
};


int main()
{
    Link link{};
    link.insert(1);
    link.insert(2);
    link.insert(3);
    link.insert(4);
    link.insert(5);

    link.printlink();

    link.delNode(4);
    link.printlink();

    Node *foundNode = link.find(3);
    if (foundNode != nullptr) {
        std::cout << "Found node: " << foundNode->val << std::endl;
    } else {
        std::cout << "Node not found" << std::endl;
    }

    return 0;
}