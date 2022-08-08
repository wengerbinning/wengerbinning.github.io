// Sequence list template class.
template <class T>
class Slist {
  private:
    T *data[];
    unsigned int count;
  public:
    Slist();
    int insert(int idx, T &element);
    T  &delete(int idx);
    ~Slist();
}