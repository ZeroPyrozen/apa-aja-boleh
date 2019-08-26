using FasterThanLight.Controller;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FasterThanLight
{
    class Program
    {
        static void Main(string[] args)
        {
            AuthController auth = new AuthController();
            auth.Index();
        }
    }
}
