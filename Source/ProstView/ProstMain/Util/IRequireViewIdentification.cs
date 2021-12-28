using System;

namespace ProstMain.Util
{
    public interface IRequireViewIdentification
    {
        Guid ViewID { get; }
    }
}