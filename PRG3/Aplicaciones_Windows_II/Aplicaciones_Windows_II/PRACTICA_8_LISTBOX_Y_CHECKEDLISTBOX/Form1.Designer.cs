namespace PRACTICA_8_LISTBOX_Y_CHECKEDLISTBOX
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.lstBxLista = new System.Windows.Forms.ListBox();
            this.chLstBxItems = new System.Windows.Forms.CheckedListBox();
            this.btnMover = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lstBxLista
            // 
            this.lstBxLista.FormattingEnabled = true;
            this.lstBxLista.Location = new System.Drawing.Point(451, 12);
            this.lstBxLista.Name = "lstBxLista";
            this.lstBxLista.Size = new System.Drawing.Size(289, 368);
            this.lstBxLista.TabIndex = 0;
            // 
            // chLstBxItems
            // 
            this.chLstBxItems.CheckOnClick = true;
            this.chLstBxItems.FormattingEnabled = true;
            this.chLstBxItems.Items.AddRange(new object[] {
            "Uno",
            "Dos",
            "Tres",
            "Cuatro",
            "Cinco",
            "Seis",
            "Siete",
            "Ocho",
            "Nueve"});
            this.chLstBxItems.Location = new System.Drawing.Point(21, 12);
            this.chLstBxItems.Name = "chLstBxItems";
            this.chLstBxItems.Size = new System.Drawing.Size(313, 364);
            this.chLstBxItems.TabIndex = 1;
            // 
            // btnMover
            // 
            this.btnMover.Location = new System.Drawing.Point(345, 125);
            this.btnMover.Name = "btnMover";
            this.btnMover.Size = new System.Drawing.Size(92, 37);
            this.btnMover.TabIndex = 2;
            this.btnMover.Text = "Mover";
            this.btnMover.UseVisualStyleBackColor = true;
            this.btnMover.Click += new System.EventHandler(this.btnMover_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(752, 392);
            this.Controls.Add(this.btnMover);
            this.Controls.Add(this.chLstBxItems);
            this.Controls.Add(this.lstBxLista);
            this.Name = "Form1";
            this.Text = "LISTBOX Y CHECKEDLISTBOX";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListBox lstBxLista;
        private System.Windows.Forms.CheckedListBox chLstBxItems;
        private System.Windows.Forms.Button btnMover;

    }
}

