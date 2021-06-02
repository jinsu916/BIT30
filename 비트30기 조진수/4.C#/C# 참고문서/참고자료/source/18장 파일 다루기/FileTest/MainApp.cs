using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace FileTest
{
    class MainApp
    {
        static void Main(string[] args)
        {
            try
            {
                DirectoryInfo dir = new DirectoryInfo("c:\\01_Down1");
                dir.MoveTo("c:\\01_Down1Change");

                Directory.Move("c:\\01_Down1Change", "c:\\01_Down1Change11");
                string[] files =
                    Directory.GetFiles("a");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            

        }
    }
}
