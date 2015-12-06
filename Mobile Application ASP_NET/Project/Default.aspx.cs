using System;
using System.IO;
using System.Collections.Generic;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    List<Company> companies = new List<Company>();

    protected void Page_Load(object sender, EventArgs e)
    {
        lblResult.Text = "";
        tbSearch.Focus();

    }
    protected void tbSearch_TextChanged(object sender, EventArgs e)
    {
        ddlCompany.Enabled = true;
        ddlCompany.Items.Clear();
        lblResult.Text = "";
        string error_msg;
        if (tbSearch.Text == "")
        {
            ddlCompany.Items.Clear();
        }
        else
        {
            companies = Query.Get_Company(tbSearch.Text, out error_msg);
            if (companies.Count > 1)
            {
                if (companies != null)
                {
                    ListItem li = new ListItem("Select Customer", "");
                    ddlCompany.Items.Add(li);
                    string prev_name = "";
                    foreach (Company company in companies)
                    {
                        if (company.Name != prev_name)
                        {
                            li = new ListItem(company.Name, company.Id);
                            ddlCompany.Items.Add(li);
                            prev_name = company.Name;
                        }
                    }
                }
                else
                {
                    lblResult.Text = "No companies found.";
                }
            }
            else if (companies.Count == 1)
            {
                ddlCompany.Enabled = false;
                string id = "";
                string name = "";
                
                foreach (Company company in companies)
                {
                    id= company.Id;
                    name = company.Name;
                }
                lblResult.Text =  name + "has " +
                Query.Get_Orders(id, out error_msg) + " orders.";
            }
            else if (companies.Count == 0)
            {
                ddlCompany.Enabled = false;
                lblResult.Text = "There are no customer names matching " + tbSearch.Text;
            }
        } 
        
    }
    protected void ddlCompany_SelectedIndexChanged(object sender, EventArgs e)
    {
        string id = "";
        string error_msg;
        if (ddlCompany.SelectedValue == "")
        {
            lblResult.Text = "";
        }
        else
        {
            id = ddlCompany.SelectedValue;
            lblResult.Text = ddlCompany.SelectedItem + "has " +
                Query.Get_Orders(id, out error_msg) + " orders.";
        }

    }
}