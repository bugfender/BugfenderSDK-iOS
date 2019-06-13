//
//  Bugfender.swift
//  Bugfender
//
//  This is a helper file for easier logging with Swift, use when building a Swift project and Bugfender is imported as static library
//  Copyright © 2017 Bugfender. All rights reserved.
//

import Foundation

#if swift(>=3.1)
    extension Bugfender {
        public class func print(_ items: Any..., separator: String = " ", terminator: String = "\n", tag: String? = nil, level: BFLogLevel = .default, filename: String = #file, line: Int = #line, funcname: String = #function)
        {
            log(items: items, separator: separator, terminator: terminator, tag: tag, filename: filename, line: line, funcname: funcname)
        }
        
        public class func error(_ items: Any..., separator: String = " ", terminator: String = "\n", tag: String? = nil, filename: String = #file, line: Int = #line, funcname: String = #function) {
            log(items: items, separator: separator, terminator: terminator, tag: tag, level: .error, filename: filename, line: line, funcname: funcname)
        }
        
        public class func warning(_ items: Any..., separator: String = " ", terminator: String = "\n", tag: String? = nil, filename: String = #file, line: Int = #line, funcname: String = #function) {
            log(items: items, separator: separator, terminator: terminator, tag: tag, level: .warning, filename: filename, line: line, funcname: funcname)
        }
        
        private class func log(items: [Any], separator: String = " ", terminator: String = "\n", tag: String? = nil, level: BFLogLevel = .default, filename: String = #file, line: Int = #line, funcname: String = #function)
        {
            let message = items.map{String(describing: $0)}.joined(separator: separator)
            let file = ("\(filename)" as NSString).lastPathComponent as String
            
            Bugfender.log(lineNumber: line, method: funcname, file: file, level: level, tag: tag, message: message)
        }
        
    }

    public func BFLog(_ format: String, _ args: CVarArg..., tag: String? = nil, level: BFLogLevel = .default, filename: String = #file, line: Int = #line, funcname: String = #function)
    {
        let message = String(format: format, arguments: args)
        let file = ("\(filename)" as NSString).lastPathComponent as String

        Bugfender.log(lineNumber: line, method: funcname, file: file, level: level, tag: tag, message: message)
    }

    public func BFLogWarn(_ format: String, _ args: CVarArg..., tag: String? = nil, filename: String = #file, line: Int = #line, funcname: String = #function)
    {
        BFLog(format, args, tag: tag, level: .warning, filename: filename, line: line, funcname: funcname)
    }

	public func BFLogErr(_ format: String, _ args: CVarArg..., tag: String? = nil, filename: String = #file, line: Int = #line, funcname: String = #function)
	{
		BFLog(format, args, tag: tag, level: .error, filename: filename, line: line, funcname: funcname)
	}

	public func BFLogTrace(_ format: String, _ args: CVarArg..., tag: String? = nil, filename: String = #file, line: Int = #line, funcname: String = #function)
	{
		BFLog(format, args, tag: tag, level: .trace, filename: filename, line: line, funcname: funcname)
	}

	public func BFLogInfo(_ format: String, _ args: CVarArg..., tag: String? = nil, filename: String = #file, line: Int = #line, funcname: String = #function)
	{
		BFLog(format, args, tag: tag, level: .info, filename: filename, line: line, funcname: funcname)
	}
	public func BFLogFatal(_ format: String, _ args: CVarArg..., tag: String? = nil, filename: String = #file, line: Int = #line, funcname: String = #function)
	{
		BFLog(format, args, tag: tag, level: .fatal, filename: filename, line: line, funcname: funcname)
	}

    public func bfprint(_ items: Any..., separator: String = " ", terminator: String = "", tag: String? = nil, level: BFLogLevel = .default, filename: String = #file, line: Int = #line, funcname: String = #function)
    {
        var message = ""
        var prefix = ""
        for item in items {
            message.write(prefix)
            print(item, separator: "", terminator: "", to: &message)
            prefix = separator
        }
        message.write(terminator)
        let file = (filename as NSString).lastPathComponent
        Bugfender.log(lineNumber: line, method: funcname, file: file, level: level, tag: tag, message: message)
    }
#elseif swift(>=3.0)
    extension Bugfender {
        public class func print(_ items: Any..., separator: String = " ", terminator: String = "\n", tag: String? = nil, level: BFLogLevel = .default, filename: String = #file, line: Int = #line, funcname: String = #function)
        {
            log(items: items, separator: separator, terminator: terminator, tag: tag, filename: filename, line: line, funcname: funcname)
        }
        
        public class func error(_ items: Any..., separator: String = " ", terminator: String = "\n", tag: String? = nil, filename: String = #file, line: Int = #line, funcname: String = #function) {
            log(items: items, separator: separator, terminator: terminator, tag: tag, level: .error, filename: filename, line: line, funcname: funcname)
        }
        
        public class func warning(_ items: Any..., separator: String = " ", terminator: String = "\n", tag: String? = nil, filename: String = #file, line: Int = #line, funcname: String = #function) {
            log(items: items, separator: separator, terminator: terminator, tag: tag, level: .warning, filename: filename, line: line, funcname: funcname)
        }
        
        private class func log(items: [Any], separator: String = " ", terminator: String = "\n", tag: String? = nil, level: BFLogLevel = .default, filename: String = #file, line: Int = #line, funcname: String = #function)
        {
            let message = items.map{String(describing: $0)}.joined(separator: separator)
            let file = ("\(filename)" as NSString).lastPathComponent as String
            
            Bugfender.log(lineNumber: line, method: funcname, file: file, level: level, tag: tag, message: message)
        }
    }

    public func BFLog(_ format: String, _ args: CVarArg..., tag: String? = nil, level: BFLogLevel = .default, filename: String = #file, line: Int = #line, funcname: String = #function)
    {
        let message = String(format: format, arguments: args)
        let file = ("\(filename)" as NSString).lastPathComponent as String

        Bugfender.log(lineNumber: line, method: funcname, file: file, level: level, tag: tag, message: message)
    }

	public func BFLogWarn(_ format: String, _ args: CVarArg..., tag: String? = nil, filename: String = #file, line: Int = #line, funcname: String = #function)
	{
		BFLog(format, args, tag: tag, level: .warning, filename: filename, line: line, funcname: funcname)
	}

	public func BFLogErr(_ format: String, _ args: CVarArg..., tag: String? = nil, filename: String = #file, line: Int = #line, funcname: String = #function)
	{
		BFLog(format, args, tag: tag, level: .error, filename: filename, line: line, funcname: funcname)
	}

	public func BFLogTrace(_ format: String, _ args: CVarArg..., tag: String? = nil, filename: String = #file, line: Int = #line, funcname: String = #function)
	{
		BFLog(format, args, tag: tag, level: .trace, filename: filename, line: line, funcname: funcname)
	}

	public func BFLogInfo(_ format: String, _ args: CVarArg..., tag: String? = nil, filename: String = #file, line: Int = #line, funcname: String = #function)
	{
		BFLog(format, args, tag: tag, level: .info, filename: filename, line: line, funcname: funcname)
	}
	public func BFLogFatal(_ format: String, _ args: CVarArg..., tag: String? = nil, filename: String = #file, line: Int = #line, funcname: String = #function)
	{
		BFLog(format, args, tag: tag, level: .fatal, filename: filename, line: line, funcname: funcname)
	}

#endif
