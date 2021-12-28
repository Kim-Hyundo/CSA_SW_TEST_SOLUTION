// -----------------------------------------------------------------------
// <copyright file="ExplorerTreeViewImageConverter.cs">
// All rights reserved.
// </copyright>
// -----------------------------------------------------------------------

namespace Javi.ExplorerTreeView
{
    using System;
    using System.Globalization;
    using System.Windows.Controls;
    using System.Windows.Data;
    using System.Windows.Media;
    using WSF.Interfaces;
    using static Javi.ExplorerTreeView.ExplorerTreeView;

    public class ExplorerTreeViewImageConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (!(value is ExplorerTreeViewItem explorerTreeViewItem))
                return (object)null;
            try
            {
                if (!(explorerTreeViewItem.Tag is IDirectoryBrowser tag))
                {
                    if (explorerTreeViewItem.Tag == null)
                        return (object)null;
                    return (object)IconExtractor.GetIconSmall(explorerTreeViewItem.Tag.ToString()).ToImageSource();
                }
                ImageSource imageSource = ((ImageSource)null ?? IconExtractor.GetIconSmall(tag.PathFileSystem).ToImageSource()) ?? IconExtractor.GetIconSmall(tag.SpecialPathId).ToImageSource();
                IntPtr ppidl;
                if (imageSource == null && PInvoke.SHParseDisplayName(tag.ParseName, IntPtr.Zero, out ppidl, 0U, out uint _) == 0U)
                    imageSource = IconExtractor.GetIconSmall(ppidl).ToImageSource();
                if (imageSource == null && tag.IconResourceId != null)
                {
                    string[] strArray = tag.IconResourceId.Split(',');
                    int result;
                    if (strArray.Length == 2 && int.TryParse(strArray[1], out result) && !string.IsNullOrEmpty(strArray[0]))
                        imageSource = IconExtractor.GetIconSmall(strArray[0], result).ToImageSource();
                }
                return (object)imageSource;
            }
            catch (Exception ex)
            {
                return explorerTreeViewItem.Tag == null ? (object)null : (object)((ImageSource)null ?? IconExtractor.GetIconSmall(explorerTreeViewItem.Tag.ToString()).ToImageSource());
            }
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
