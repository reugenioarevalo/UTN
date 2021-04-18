namespace MiPrimerAplicacion
{
    partial class MiPrimeraAplicacion
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
            this.btnTocame = new System.Windows.Forms.Button();
            this.lblEtiqueta = new System.Windows.Forms.Label();
            this.txtDescripcion = new System.Windows.Forms.TextBox();
            this.txtDetalle = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // btnTocame
            // 
            this.btnTocame.BackColor = System.Drawing.Color.Indigo;
            this.btnTocame.Font = new System.Drawing.Font("Arial Unicode MS", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.btnTocame.ForeColor = System.Drawing.Color.White;
            this.btnTocame.Image = global::MiPrimerAplicacion.Properties.Resources.logoico;
            this.btnTocame.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnTocame.Location = new System.Drawing.Point(12, 67);
            this.btnTocame.Name = "btnTocame";
            this.btnTocame.Size = new System.Drawing.Size(244, 72);
            this.btnTocame.TabIndex = 0;
            this.btnTocame.Text = "Modo Dark";
            this.btnTocame.UseVisualStyleBackColor = false;
            this.btnTocame.Click += new System.EventHandler(this.btnTocame_Click);
            // 
            // lblEtiqueta
            // 
            this.lblEtiqueta.AutoSize = true;
            this.lblEtiqueta.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lblEtiqueta.Font = new System.Drawing.Font("Microsoft YaHei UI", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblEtiqueta.ForeColor = System.Drawing.Color.White;
            this.lblEtiqueta.Location = new System.Drawing.Point(12, 9);
            this.lblEtiqueta.Name = "lblEtiqueta";
            this.lblEtiqueta.Size = new System.Drawing.Size(219, 37);
            this.lblEtiqueta.TabIndex = 1;
            this.lblEtiqueta.Text = "Pase por arriba ";
            this.lblEtiqueta.Click += new System.EventHandler(this.lblEtiqueta_Click);
            this.lblEtiqueta.MouseLeave += new System.EventHandler(this.lblEtiqueta_MouseLeave);
            this.lblEtiqueta.MouseMove += new System.Windows.Forms.MouseEventHandler(this.lblEtiqueta_MouseMove);
            // 
            // txtDescripcion
            // 
            this.txtDescripcion.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtDescripcion.Location = new System.Drawing.Point(12, 166);
            this.txtDescripcion.MaxLength = 20;
            this.txtDescripcion.Name = "txtDescripcion";
            this.txtDescripcion.Size = new System.Drawing.Size(457, 20);
            this.txtDescripcion.TabIndex = 2;
            this.txtDescripcion.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtDescripcion_KeyPress);
            // 
            // txtDetalle
            // 
            this.txtDetalle.Location = new System.Drawing.Point(157, 234);
            this.txtDetalle.Multiline = true;
            this.txtDetalle.Name = "txtDetalle";
            this.txtDetalle.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtDetalle.Size = new System.Drawing.Size(351, 68);
            this.txtDetalle.TabIndex = 3;
            this.txtDetalle.Leave += new System.EventHandler(this.txtDetalle_Leave);
            // 
            // MiPrimeraAplicacion
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DodgerBlue;
            this.ClientSize = new System.Drawing.Size(1076, 500);
            this.Controls.Add(this.txtDetalle);
            this.Controls.Add(this.txtDescripcion);
            this.Controls.Add(this.lblEtiqueta);
            this.Controls.Add(this.btnTocame);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "MiPrimeraAplicacion";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Mi primera aplicacion";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.MiPrimeraAplicacion_FormClosed);
            this.Load += new System.EventHandler(this.MiPrimeraAplicacion_Load);
            this.Click += new System.EventHandler(this.MiPrimeraAplicacion_Click);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnTocame;
        private System.Windows.Forms.Label lblEtiqueta;
        private System.Windows.Forms.TextBox txtDescripcion;
        private System.Windows.Forms.TextBox txtDetalle;
    }
}

