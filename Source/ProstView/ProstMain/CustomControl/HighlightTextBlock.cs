﻿using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Media;

namespace ProstMain.CustomControl
{
    public class HighlightTextBlock : TextBlock
    {
        #region Properties

        public new string Text
        {
            get { return (string)GetValue(TextProperty); }
            set { SetValue(TextProperty, value); }
        }

        public new static readonly DependencyProperty TextProperty =
            DependencyProperty.Register("Text", typeof(string),
            typeof(HighlightTextBlock), new FrameworkPropertyMetadata(string.Empty, FrameworkPropertyMetadataOptions.AffectsRender,
                new PropertyChangedCallback(UpdateHighlighting)));

        public string HighlightPhrase
        {
            get { return (string)GetValue(HighlightPhraseProperty); }
            set { SetValue(HighlightPhraseProperty, value); }
        }

        public static readonly DependencyProperty HighlightPhraseProperty =
            DependencyProperty.Register("HighlightPhrase", typeof(string),
            typeof(HighlightTextBlock), new FrameworkPropertyMetadata(String.Empty, FrameworkPropertyMetadataOptions.AffectsRender,
                new PropertyChangedCallback(UpdateHighlighting)));

        public Brush HighlightBrush
        {
            get { return (Brush)GetValue(HighlightBrushProperty); }
            set { SetValue(HighlightBrushProperty, value); }
        }

        public static readonly DependencyProperty HighlightBrushProperty =
            DependencyProperty.Register("HighlightBrush", typeof(Brush),
            typeof(HighlightTextBlock), new FrameworkPropertyMetadata(Brushes.Yellow, FrameworkPropertyMetadataOptions.AffectsRender,
                new PropertyChangedCallback(UpdateHighlighting)));

        public bool IsCaseSensitive
        {
            get { return (bool)GetValue(IsCaseSensitiveProperty); }
            set { SetValue(IsCaseSensitiveProperty, value); }
        }

        public static readonly DependencyProperty IsCaseSensitiveProperty =
            DependencyProperty.Register("IsCaseSensitive", typeof(bool),
            typeof(HighlightTextBlock), new FrameworkPropertyMetadata(false, FrameworkPropertyMetadataOptions.AffectsRender,
                new PropertyChangedCallback(UpdateHighlighting)));

        private static void UpdateHighlighting(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            ApplyHighlight(d as HighlightTextBlock);
        }

        #endregion

        #region Members

        private static void ApplyHighlight(HighlightTextBlock tb)
        {
            string highlightPhrase = tb.HighlightPhrase;
            string text = tb.Text;

            if (text == null)
                return;

            if (String.IsNullOrEmpty(highlightPhrase))
            {
                tb.Inlines.Clear();

                tb.Inlines.Add(text);
            }

            else
            {
                int index = text.IndexOf(highlightPhrase, (tb.IsCaseSensitive) ? StringComparison.Ordinal : StringComparison.OrdinalIgnoreCase);

                tb.Inlines.Clear();

                if (index < 0) //if highlightPhrase doesn't exist in text
                    tb.Inlines.Add(text); //add text, with no background highlighting, to tb.Inlines

                else
                {
                    if (index > 0) //if highlightPhrase occurs after start of text
                        tb.Inlines.Add(text.Substring(0, index)); //add the text that exists before highlightPhrase, with no background highlighting, to tb.Inlines

                    //add the highlightPhrase, using substring to get the casing as it appears in text, with a background, to tb.Inlines
                    tb.Inlines.Add(new Run(text.Substring(index, highlightPhrase.Length))
                    {
                        Background = tb.HighlightBrush
                    });

                    index += highlightPhrase.Length; //move index to the end of the matched highlightPhrase

                    if (index < text.Length) //if the end of the matched highlightPhrase occurs before the end of text
                        tb.Inlines.Add(text.Substring(index)); //add the text that exists after highlightPhrase, with no background highlighting, to tb.Inlines
                }
            }
        }

        #endregion
    }
}