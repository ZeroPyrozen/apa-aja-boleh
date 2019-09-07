using FasterThanLight.Model;
using FasterThanLight.View.Auth;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FasterThanLight.Controller
{
    public class AuthController
    {
        public void Index()
        { 
            AuthIndex auth = new AuthIndex();
            auth.LoadView();
        }
        public bool UserInput(int userInput)
        {
            AuthIndex auth = new AuthIndex();
            bool result = false;
            switch (userInput)
            {
                case 1:
                    result = true;
                    auth.Login();
                    break;
                case 2:
                    result = true;
                    auth.Register();
                    break;
                case 3:
                    result = true;
                    Console.WriteLine("Exiting Program...\nPress Enter to Continue");
                    Console.ReadLine();
                    Environment.Exit(0);
                    break;
            }
            return result;
        }
        public bool Login(AuthModel authModel)
        {
            bool result = false;
            Console.WriteLine(authModel.userName+" "+authModel.passWord);
            result = true;
            return result;
        }
        public bool IsUserNameExist(string UserName)
        {
            return true;
        }
    }
}
