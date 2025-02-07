using System;
using System.Collections.Generic;
using System.Net;


namespace ConsoleApp1 {
    class Program{
        public static void Main(string[] args) {
            var numbers = new List<int> { -1, -2, -2, -3,-3};
            if (numbers == null) {
                throw new ArgumentNullException();
            }
            var smallests = GetSmallests(numbers, 3);

            foreach (var number in smallests)
                Console.WriteLine(number);
        }
        public static List<int> GetSmallests(List<int> list, int count){
            var variablelist = new List<int>(list);
            if (list.Count < count || count <=0){
                Console.WriteLine("Unable to find list of smallest numbers");
                return list;
            }
            var smallests = new List<int>();
            while (smallests.Count < count){
                    var min = GetSmallest(variablelist);
                    if ((smallests.Contains(min)==false)) {
                        
                        smallests.Add(min);
                    }
                    variablelist.Remove(min);
                    
            }
            return smallests;
        }
        
        public static int GetSmallest(List<int> list){
            var min = list[0];
            //Console.WriteLine($"Index [0]: {min}");
            for (var i = 1; i < list.Count; i++){
                if (list[i] < min)
                    min = list[i];
            }
            return min;
        }
    }
}
