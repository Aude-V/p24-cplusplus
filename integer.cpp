class Integer {
    private:
        int value{12};
    public:
        Integer (int v=0): // par défaut, l'argument est 0 (si aucun argument n'est donné)
            value(v){
            }
};

int main ()
{
    Integer i(-17);
    Integer k;
    return 0;
}