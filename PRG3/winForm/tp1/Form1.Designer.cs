namespace tp1
{
    partial class TP1
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
            this.txtNombre = new System.Windows.Forms.TextBox();
            this.btnSaludar = new System.Windows.Forms.Button();
            this.cboColores = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // txtNombre
            // 
            this.txtNombre.Location = new System.Drawing.Point(278, 56);
            this.txtNombre.Name = "txtNombre";
            this.txtNombre.Size = new System.Drawing.Size(298, 20);
            this.txtNombre.TabIndex = 0;
            this.txtNombre.Text = "Nobre";
            this.txtNombre.TextChanged += new System.EventHandler(this.txtNombre_TextChanged);
            // 
            // btnSaludar
            // 
            this.btnSaludar.BackColor = System.Drawing.SystemColors.GrayText;
            this.btnSaludar.Font = new System.Drawing.Font("Adobe Heiti Std R", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSaludar.ForeColor = System.Drawing.SystemColors.HighlightText;
            this.btnSaludar.Location = new System.Drawing.Point(278, 137);
            this.btnSaludar.Name = "btnSaludar";
            this.btnSaludar.Size = new System.Drawing.Size(298, 67);
            this.btnSaludar.TabIndex = 1;
            this.btnSaludar.Text = "Saludar ";
            this.btnSaludar.UseVisualStyleBackColor = false;
            this.btnSaludar.Click += new System.EventHandler(this.button1_Click);
            // 
            // cboColores
            // 
            this.cboColores.FormattingEnabled = true;
            this.cboColores.Location = new System.Drawing.Point(607, 148);
            this.cboColores.Name = "cboColores";
            this.cboColores.Size = new System.Drawing.Size(121, 21);
            this.cboColores.TabIndex = 2;
            // 
            // TP1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.InactiveCaption;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.cboColores);
            this.Controls.Add(this.btnSaludar);
            this.Controls.Add(this.txtNombre);
            this.Name = "TP1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "winForm1 tp1";
            this.Load += new System.EventHandler(this.TP1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtNombre;
        private System.Windows.Forms.Button btnSaludar;
        private System.Windows.Forms.ComboBox cboColores;
    }
}

