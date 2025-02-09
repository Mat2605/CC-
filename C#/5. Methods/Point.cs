namespace ConsoleApp1;

public class Point {
    public int X;
    public int Y;

    public Point(int x, int y)
    {
        this.X = x;
        this.Y = y;
        
    }

    public void Move(int dx, int dy)
    {
        this.X += dx;
        this.Y += dy;
    }

    public void Move(Point newPoint)
    {
        if (newPoint == null)
        {
            throw new ArgumentNullException(nameof(newPoint));
            
        }
        Move(newPoint.X, newPoint.Y);
        
    }

    public void adicionarPosicoesX(params int[] numbers) {

        foreach (var number in numbers) {
            
            Move(number,0);
        }
    }

    public void Converter()
    {
        try
        {
            int number;
            int.TryParse("A",out number);
            Console.WriteLine(" {0} ",number);
        }
        catch (Exception)
        {
            Console.WriteLine("Error");

        }
    }
        
}