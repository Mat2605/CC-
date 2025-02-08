namespace NewConsoleApp;

public class Customer
{
    public int Id;
    public string Name;
    public List<Order> Orders;

    public Customer()
    {
        Orders = new List<Order>();
    }

    public Customer(int varId, string varName) : this(varId){
        this.Name = varName;
    }

    public Customer(int varId) : this() {
        this.Id = varId; 
        //Já chama o primeiro método construtor
      }
}