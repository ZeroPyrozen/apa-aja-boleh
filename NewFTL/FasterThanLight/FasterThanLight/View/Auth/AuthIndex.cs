﻿using FasterThanLight.Controller;
using FasterThanLight.Model;
using FasterThanLight.View.Layout;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace FasterThanLight.View.Auth
{
    public class AuthIndex : BaseView
    {       
        public void LoadView()
        {
            DisplaySpacing();
            DisplayTitle();
            DisplayMenu();
            MenuInput();
        }
        public void DisplayTitle()
        { 
            Thread.Sleep(100);
            Console.Write("    ______           __               ________                   __    _       __    __ ");
            Console.Write("\n");
            Thread.Sleep(100);
            Console.Write("   / ____/___ ______/ /____  _____   /_  __/ /_  ____ _____     / /   (_)___ _/ /_  / /_");
            Console.Write("\n");
            Thread.Sleep(100);
            Console.Write("  / /_  / __ `/ ___/ __/ _ \\/ ___/    / / / __ \\/ __ `/ __ \\   / /   / / __ `/ __ \\/ __/");
            Console.Write("\n");
            Thread.Sleep(100);
            Console.Write(" / __/ / /_/ (__  ) /_/  __/ /       / / / / / / /_/ / / / /  / /___/ / /_/ / / / / /_  ");
            Console.Write("\n");
            Thread.Sleep(100);
            Console.Write("/_/    \\__,_/____/\\__/\\___/_/       /_/ /_/ /_/\\__,_/_/ /_/  /_____/_/\\__, /_/ /_/\\__/  ");
            Console.Write("\n");
            Thread.Sleep(100);
            Console.Write("                                                                     /____/             ");
            Console.Write("\n");
        }
        public void DisplayMenu()
        { 
            Console.Write("1. Login\n");
            Console.Write("2. Register\n");
            Console.Write("3. Exit\nChoose: ");
        }
        public void Login()
        {
            AuthModel authModel = new AuthModel();
            AuthController authController = new AuthController();
            bool flag = false;
            do
            {
                Console.Write("Username: ");
                authModel.userName = Console.ReadLine();
                Console.Write("Password: ");
                authModel.passWord = Console.ReadLine();
                if (authModel.userName.Trim() == "" || authModel.passWord.Trim() == "")
                {
                    Console.WriteLine("Please Fill All Input!");
                }
                else
                {
                    flag = authController.Login(authModel);
                    if (flag == false)
                    {
                        Console.WriteLine("Wrong Username/Password!");
                        authModel.userName = "";
                        authModel.passWord = "";
                    }
                }
            }while(flag==false);
            
        }
        public void Register()
        {
            string userName;
            int flag = 0;
            Console.Clear();
            Console.Write("_ __                                          _ _ _             \n");
            Console.Write("' )  )             _/_         _/_            ' ) ) )               \n");
            Console.Write(" /--' _  _,  o _   /  __  __.  /  o __ ____    / / / _  ____  . .\n");
            Console.Write("/  \\_</_(_)_<_/_)_<__/ (_(_/|_<__<_(_)/ / <_  / ' (_</_/ / <_(_/_\n");
            Console.Write("         /|                                                      \n");
            Console.Write("        |/                                                       ");
            DisplaySpacing();
            do
            {
                flag = 0;
                userName = "";
                Console.Write("Insert your UserName [5-30 Characters or Enter \"Cancel\" to Cancel Registration]: ");
                userName = Console.ReadLine();
                if (userName.Trim().Length > 30 || userName.Trim().Length < 5)
                {
                    flag = 0;
                    Console.WriteLine("Please enter Username greater than 5 character and less than 30 character");
                }
                else
                {
                    userName = userName.Trim();
                    if (userName.Trim().ToLower() == "cancel")
                    {
                        Console.Write("Cancelling user creation...\nPress Enter to Continue...");
                        return;
                    }
                    else
                    {
                        AuthController authController = new AuthController();
                        bool isUserExist = authController.IsUserNameExist(userName.Trim());
                        if(isUserExist == false)
                        {
                            flag = 1;
                        }
                        else
                        {
                            flag = 0;
                        }
                    }
                }
            } while (flag == 0);

        }
        public void MenuInput()
        {
            bool flag = false;
            int userInput;
            AuthController authController;
            do
            {
                flag = int.TryParse(Console.ReadLine(), out userInput);
                if (flag == true)
                {
                    authController = new AuthController();
                    flag = authController.UserInput(userInput);
                }
                else
                {
                    Console.WriteLine("Please Choose Only 1 Option!");
                    Console.Write("Choose: ");
                }
            }while(flag==false);
        }
    }
}
