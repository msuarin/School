<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Northwind Traders</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <p style="text-align: center;">
            <asp:Label ID="Label1" runat="server" 
                Text="Northwind Traders Orders " Font-Bold="True" Font-Size="XX-Large" 
                ForeColor="Blue" Font-Names="Arial"></asp:Label></p>
        <br />
        <br />
        <table style="margin: auto;">
        <tr>
            <td><asp:Label ID="Label2" runat="server" Text="Company Name" Font-Bold="True" 
                    Font-Names="Arial"></asp:Label></td>
        </tr>
        <tr>
        <td>
            <asp:Label ID="Label3" runat="server" Text="One or more initial letters" 
                Font-Bold="True" Font-Names="Arial"></asp:Label></td>
        </tr>
        <tr>
        <td><asp:TextBox ID="tbSearch" runat="server" AutoPostBack="True" 
                Font-Names="Arial" Width="200px" ontextchanged="tbSearch_TextChanged"></asp:TextBox></td>
        <td>
            <asp:DropDownList ID="ddlCompany" runat="server" Font-Names="Arial" 
                Width="180px" AutoPostBack="True" 
                onselectedindexchanged="ddlCompany_SelectedIndexChanged">
            </asp:DropDownList>
        </td>
        </tr>
        
        </table>
        <br />
        <br />
        <p style="text-align: center;"><asp:Label ID="lblResult" runat="server"></asp:Label></p>
        
    
    </div>
    </form>
</body>
</html>
