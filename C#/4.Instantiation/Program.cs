namespace ConsoleApp1 {
    public class Program
    {
        public int id;
        public string name;
        public readonly List<Orders> orders = new List<Orders>(); //Garantir que seja sempre instanciado
        //apenas uma vez com readonly

        public Program()
        {
            //Garantir que sempre seja chamado
            orders = new List<Orders>();
        }
        public Program(int id) : this()
        {
            this.id = id;
        }

        public Program(int id, string name) : this(id) {
           
            this.name = name;
        }

        public void Promote()
        {
            //orders = new List<Orders>();
        }
        
        
        public static void Main(string[] args)
        {
            Program obj = new Program(1, "Matheus");
            obj.orders.Add(new Orders());

        }
    }
    
}

