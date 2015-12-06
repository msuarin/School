using System;
using System.Data;
using System.IO;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Web.Configuration;

/// <summary>
/// Summary description for Query
/// </summary>
public class Query
{
    public static List<Company> Get_Company( string searchCompany,
                                out string error_msg)
    {
        SqlDataReader rdr = null;
        SqlConnection cn = null;
        List<Company> companies = new List<Company>();
        error_msg = "";
        try
        {
            cn = Setup_Connection();
            rdr = Get_Reader(searchCompany, cn); // Perform the query
            //Process Query Result
            if (rdr.HasRows)
            {
                while (rdr.Read())
                {
                    Company company = new Company(rdr);
                    companies.Add(company);
                }
            }
            else
            {
                error_msg = "No companies found.";
            }
        }
        catch (Exception ex)
        {
            error_msg = "ERROR: " + ex.Message;
        }
        finally
        {
            if (rdr != null)
            {
            rdr.Close();
            }
            if (cn != null)
            {
                cn.Close();
            }
        }   
        return companies;
    }

    public static int Get_Orders(string ID, out string error_msg)
    {
        int count = 0;
        SqlDataReader rdr = null;
        SqlConnection cn = null;
        error_msg = "";
        try
        {
            cn = Setup_Connection();
            rdr = Lookup_Orders(ID, cn); // Perform the query
            //Process Query Result
            if (rdr.HasRows)
            {
                while (rdr.Read())
                {
                    count++;
                }
            }
            else
            {
                error_msg = "No orders found.";
            }
        }
        catch (Exception ex)
        {
            error_msg = "ERROR: " + ex.Message;
        }
        finally
        {
            if (rdr != null)
            {
                rdr.Close();
            }
            if (cn != null)
            {
                cn.Close();
            }
        }   
        return count;
    }

    public static SqlConnection Setup_Connection()
    {
        String connection_string =
WebConfigurationManager.ConnectionStrings["CompanyOrders"].ConnectionString;
        SqlConnection cn = new SqlConnection(connection_string);
        cn.Open();
        return cn;
    }

    public static SqlDataReader Get_Reader(string searchCompany,
                                        SqlConnection cn)
    {
        SqlCommand cmd = new SqlCommand();
        cmd.CommandText = "SELECT * FROM Customers " +
        "WHERE upper(companyname) like upper('" + searchCompany + "%')";
        cmd.Connection = cn;
        return cmd.ExecuteReader();
    }

    public static SqlDataReader Lookup_Orders(string ID, SqlConnection cn)
    {
        SqlCommand cmd = new SqlCommand();
        cmd.CommandText = "SELECT * FROM Orders " +
            "WHERE CustomerID='" + ID + "'";
        cmd.Connection = cn;
        return cmd.ExecuteReader();


        
    }
	public Query()
	{
		//
		// TODO: Add constructor logic here
		//
	}
}