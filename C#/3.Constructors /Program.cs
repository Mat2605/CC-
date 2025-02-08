namespace NewConsoleApp;

public class Program {
    public static void Main(string[] args)
    {
        var objetoCustomerPadrao = new Customer();
        var objetoCustomer = new Customer(26,"Matheus");
        Console.WriteLine("{0} | {1} ", objetoCustomer.Id,objetoCustomer.Name);
        Console.WriteLine(objetoCustomerPadrao);

    }
    
}