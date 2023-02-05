//
Objects on the stack and heap
    // 1. stack obj goes away out of scope
    // 2. on the heap :
    //  Ex* ptr = new Ex();
    // have to delete this object by delete ptr. if ptr goes away before deleting the obj,

    class DArray
{
    int len;
    int *data = nullptr;

public:
    Darray(int len = 5) : len(len)
    {
    }

    ~DArray(){
        delete [] data;
    }

    // getter
    int operator[](int index) const
    {
    }

    // setter
    int &operator[](int index)
    {
        return data[index];
    }

    int length() const
    {
        return len;
    }

    void resize(int newsize)
    {
        int *newdata = new int[newsize];
        for (int i; i < len && i < newsize; i++)
        {
            newdata[i] = data[i];
        }

        delete[] data;
        data = newdata;
        len = newsize;
    }  
};

//print array customized way
  std::ostream&   operator<<(std::ostream& output, const DArray& vals){
        output << "["; 
        for(int i=0; i< vals.length()-1; i++){
        output << vals[i] << ", " ;
        }
        if(vals.length()>0){
            output << vals[vals.length()-1];
        }
        output << "]"; 

    }