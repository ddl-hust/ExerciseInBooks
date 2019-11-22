{ // new scope
// p and p2 point to dynamically allocated objects
Sales_data *p = new Sales_data; // p is a built-in pointer
auto p2 = make_shared<Sales_data>(); // p2 is a shared_ptr
Sales_data item(*p); // copy constructor copies *p into item
vector<Sales_data> vec; // local object
vec.push_back(*p2); // copies the object to which p2 points
delete p; // destructor called on the object pointed to
by p
}