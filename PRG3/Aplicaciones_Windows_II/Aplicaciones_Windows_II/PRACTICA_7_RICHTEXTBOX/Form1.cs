using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PRACTICA_7_RICHTEXTBOX
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void btnNegrita_Click(object sender, EventArgs e)
        {
            Font viejaFuente;//Declaro una variable Class Font para la Fuente Vieja
            Font nuevaFuente; //Declaro una variable Class Font para la Fuente Nueva
            //Asigno a  viejaFuente el tipo de fuente seleccionado.
            //Obtenfo el tipo de fuente a traves de la propiedad SelectionFont
            //del control RicheTectBox
            viejaFuente = rtxtEditor.SelectionFont;
            if (viejaFuente.Bold)
                //si ya tiene negrita, establece la nuevaFuente siun Negrita
                nuevaFuente = new Font(viejaFuente, viejaFuente.Style & ~FontStyle.Bold);
            else
                //si no tenia negrita, establece nuevafuete con Negrita
                nuevaFuente = new Font(viejaFuente, viejaFuente.Style | FontStyle.Bold);

            //establzco la nuevaFuente  a la seleccion.
            rtxtEditor.SelectionFont = nuevaFuente;
            //realizo un foco para posicionarme en el control 
            rtxtEditor.Focus();
        }

        private void btnSubrayado_Click(object sender, EventArgs e)
        {
            Font viejaFuente;//Declaro la Variable Claas Font para la fuente Vieja
            Font nuevaFuente;// Declaro la variable Class Font para la fuente nueva
                             //asigno a viejaFuente el tipo de fuente selccion
                             //obtengo el tipo de fuiente atraves de la propiuedad seletionFont
                             //del control RichTectBox

            viejaFuente = rtxtEditor.SelectionFont;
            if (viejaFuente.Underline)
                nuevaFuente = new Font(viejaFuente, viejaFuente.Style & ~FontStyle.Underline);
            else
                nuevaFuente = new Font(viejaFuente, viejaFuente.Style | FontStyle.Underline);

            rtxtEditor.SelectionFont = nuevaFuente;
            rtxtEditor.Focus();


        }

        private void btnCursiva_Click(object sender, EventArgs e)
        {
            Font viejaFuente;
            Font nuevaFuente;
            viejaFuente = rtxtEditor.SelectionFont;
            if (viejaFuente.Italic)
                nuevaFuente = new Font(viejaFuente, viejaFuente.Style & ~FontStyle.Italic);
            else
                nuevaFuente = new Font(viejaFuente, viejaFuente.Style | FontStyle.Italic);
            rtxtEditor.SelectionFont = nuevaFuente;
            rtxtEditor.Focus();

        }

        private void btnCentrado_Click(object sender, EventArgs e)
        {
            //atravez de la propiedad selectionAlignment obtiene la alineacion
            //del texto que se eselleccion 

            if (rtxtEditor.SelectionAlignment == HorizontalAlignment.Center)
                rtxtEditor.SelectionAlignment = HorizontalAlignment.Left;
            else
                rtxtEditor.SelectionAlignment = HorizontalAlignment.Center;
            rtxtEditor.Focus();
        }
        private void AplicarTamanioText(string textSize)
        {
            float nuevoTam = Convert.ToSingle(textSize);
            FontFamily actualFuenteFamily;
            Font nuevaFuente;
            actualFuenteFamily = rtxtEditor.SelectionFont.FontFamily;
            nuevaFuente = new Font(actualFuenteFamily, nuevoTam);
            rtxtEditor.SelectionFont = nuevaFuente;
        }

        private void txtTamanio_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((e.KeyChar < 48 || e.KeyChar > 57) && e.KeyChar != 8 && e.KeyChar != 13)
                e.Handled = true;
            else if(e.KeyChar == 13)
            {
                if (txtTamTexto.Text.Length > 0)
                    AplicarTamanioText(txtTamTexto.Text);
                
                e.Handled = true;
                rtxtEditor.Focus();
            }
        }

        private void txtTamani_Validated(object sender, EventArgs e)
        {
            AplicarTamanioText(((TextBox)sender).Text);
            rtxtEditor.Focus();
        }

        private void rtxtEditor_LinkCliked(object sender, LinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start(e.LinkText);
        }

        private void btnAbrir_Click(object sender, EventArgs e)
        {
            try
            {
                rtxtEditor.LoadFile("Test.rtf");
            }
            catch (System.IO.FileNotFoundException)
            {
                MessageBox.Show("No se puedo cargar el archivo ");
                
            }
        }

        private void btnGuardar_Click(object sender, EventArgs e)
        {
            try
            {
                rtxtEditor.SaveFile("Test.rtf");
            }
            catch (System.Exception err)
            {
                MessageBox.Show(err.Message);
                
            }
        }
    }
}
