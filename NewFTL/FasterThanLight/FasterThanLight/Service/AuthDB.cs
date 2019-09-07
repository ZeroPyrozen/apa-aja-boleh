using FasterThanLight.Model;
using Microsoft.ApplicationBlocks.Data;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FasterThanLight.Service
{
    public interface IAuthDB
    {
        AuthModel CheckUsernameAvailability(string userName);
    }
    public class AuthDB : IAuthDB
    {
        public AuthModel CheckUsernameAvailability(string userName)
        {
            AuthModel auth = new AuthModel();
            try
            {
                auth.userName = "";
                string spName = "FTL_User_CheckUsernameAvailability";
                SqlParameter[] sqlParameters = new SqlParameter[1];
                sqlParameters[0] = new SqlParameter("@UserName", SqlDbType.VarChar);
                sqlParameters[0].Direction = ParameterDirection.Input;
                sqlParameters[0].Value = userName;

                using
                (
                    SqlDataReader sqlDataReader = SqlHelper.ExecuteReader(
                        ConfigurationManager.ConnectionStrings["DefaultConnection"].ConnectionString,
                        CommandType.StoredProcedure,
                        spName, sqlParameters)
                )
                {
                    if(sqlDataReader.HasRows)
                    {
                        if(sqlDataReader.Read())
                        {
                            auth.userName = sqlDataReader["Username"].ToString();
                        }
                    }
                    sqlDataReader.Close();
                }

                return auth;
            }
            catch(Exception ex)
            {
                throw ex;
            }

        }
    }
}
