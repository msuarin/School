using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Web;

/// <summary>
/// Summary description for Company
/// </summary>
public class Company
{
    private string id;

    public string Id
    {
        get { return id; }
    }
    private string name;

    public string Name
    {
        get { return name; }
        set { name = value; }
    }
    private int orders;

    public int Orders
    {
        get { return orders; }
        set { orders = value; }
    }

	public Company(SqlDataReader rdr)
	{
        id = (string) rdr["CustomerID"];
        name = (string) rdr["CompanyName"];
        orders = 0;
	}
}