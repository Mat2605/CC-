namespace ConsoleApp1 {
    
    class Program {
        
        public static void Main(string[] args)
        {

            var objPoint = new Point(10,20);
            Console.WriteLine("[{0},{1}]",objPoint.X,objPoint.Y);
            objPoint.Move((new Point(15,30)));
            Console.WriteLine("[{0},{1}]",objPoint.X,objPoint.Y);
            objPoint.adicionarPosicoesX(1,2,3,4,5,6);
            Console.WriteLine("[{0},{1}]",objPoint.X,objPoint.Y);
            objPoint.Converter();
        }
        
    }
}