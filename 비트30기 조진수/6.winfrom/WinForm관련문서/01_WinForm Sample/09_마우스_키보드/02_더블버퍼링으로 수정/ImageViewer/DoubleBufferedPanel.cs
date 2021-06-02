using System;
using System.Collections.Generic;
using System.Text;

namespace ImageViewer
{
    class DoubleBufferedPanel: System.Windows.Forms.Panel
    {

    public DoubleBufferedPanel()

    {

        this.SetStyle(System.Windows.Forms.ControlStyles.UserPaint, true);

        this.SetStyle(System.Windows.Forms.ControlStyles.OptimizedDoubleBuffer | System.Windows.Forms.ControlStyles.AllPaintingInWmPaint, true);

        this.SetStyle(System.Windows.Forms.ControlStyles.EnableNotifyMessage, true);

    }

 

    protected override void OnNotifyMessage(System.Windows.Forms.Message m)

    {

        if (m.Msg != 0x0014) // WM_ERASEBKGND == 0X0014

        {

            base.OnNotifyMessage(m);

        }

    }

}
}
