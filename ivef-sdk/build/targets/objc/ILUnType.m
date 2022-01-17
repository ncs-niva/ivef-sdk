
#import "ILUnType.h"


@implementation ILUnType

- (id) init {
    self = [super init];
    if (self != nil) {
        m_codeAPresent = NO;
        m_codeBPresent = NO;
        m_modePresent = NO;
    }
    return self;
}

- (void) dealloc {

    [m_codeA release];
    [m_codeB release];
    [super dealloc];
}

- (NSString*) stringFromDate:(NSDate *)date {

     // new date strings can be in Zulu time
     static NSDateFormatter *formatterWithMillies = nil;
     NSTimeZone *timeZone = [NSTimeZone timeZoneWithName:@"UTC"];
     if (date == nil) {
         return @""; // illigal date
     }
     if (formatterWithMillies == nil) {
         formatterWithMillies = [[NSDateFormatter alloc] initWithDateFormat: @"%Y-%m-%dT%H:%M:%S.%F" allowNaturalLanguage:NO];
     }
     [formatterWithMillies setTimeZone:timeZone];
#if defined (__clang__)
     return [[formatterWithMillies stringForObjectValue:date] stringByAppendingString:@"Z"]; // always zulu time
#else
     return [[formatterWithMillies stringFromDate:date] stringByAppendingString:@"Z"]; // always zulu time
#endif
}

- (NSDate*) dateFromString:(NSString *)str {

     static NSDateFormatter *formatterWithMillies = nil;
     if (formatterWithMillies == nil) {
         formatterWithMillies = [[NSDateFormatter alloc] initWithDateFormat: @"%Y-%m-%dT%H:%M:%S.%F" allowNaturalLanguage:NO];
     }
     static NSDateFormatter *formatterWithSeconds = nil;
     if (formatterWithSeconds == nil) {
         formatterWithSeconds = [[NSDateFormatter alloc] initWithDateFormat: @"%Y-%m-%dT%H:%M:%S" allowNaturalLanguage:NO];
     }
     static NSDateFormatter *formatterWithMinutes = nil;
     if (formatterWithMinutes == nil) {
         formatterWithMinutes = [[NSDateFormatter alloc] initWithDateFormat: @"%Y-%m-%dT%H:%M" allowNaturalLanguage:NO];
     }
     // new date strings can be in Zulu time
     NSTimeZone *timeZone = [NSTimeZone timeZoneWithName:@"UTC"];
     if ([str characterAtIndex: [str length] - 1] == 'Z') {
         [formatterWithMillies setTimeZone:timeZone]; // localtime is default
         [formatterWithSeconds setTimeZone:timeZone]; // localtime is default
         [formatterWithMinutes setTimeZone:timeZone]; // localtime is default
#if defined (__clang__)
         str = [str stringByReplacingString:@"Z" withString:@""];

#else
         str = [str stringByReplacingOccurrencesOfString:@"Z" withString:@""];

#endif
     }
     // convert
#if defined (__clang__)
     NSDate *val;
     [formatterWithMillies getObjectValue: &val forString: str errorDescription: nil];
#else
     NSDate *val = [formatterWithMillies dateFromString:str];
#endif
     if (val) {
         return val;
     }
#if defined (__clang__)
     [formatterWithSeconds getObjectValue: &val forString: str errorDescription: nil];
#else
     val = [formatterWithSeconds dateFromString:str];
#endif
     if (val) {
         return val;
     }
#if defined (__clang__)
     [formatterWithMinutes getObjectValue: &val forString: str errorDescription: nil];
#else
     val = [formatterWithMinutes dateFromString:str];
#endif
     if (val) {
         return val;
     }
     return nil; // invalid date
}

-(BOOL) setCodeA:(NSString *) val {

    m_codeAPresent = YES;
    [m_codeA release];
    m_codeA = val;
    [m_codeA retain];
    return YES;
}

- (NSString *) codeA {

    return m_codeA;
}

-(BOOL) setCodeB:(NSString *) val {

    m_codeBPresent = YES;
    [m_codeB release];
    m_codeB = val;
    [m_codeB retain];
    return YES;
}

- (NSString *) codeB {

    return m_codeB;
}

-(BOOL) hasCodeB {

    return m_codeBPresent;
}

-(BOOL) setMode:(int) val {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 6 ) &&
         ( val != 7 ) &&
         ( val != 8 ) )
        return NO;
    m_modePresent = YES;
    m_mode = val;
    return YES;
}

- (int) mode {

    return m_mode;
}

-(BOOL) setAttributes:(NSDictionary *)attributeDict {

#if defined (__clang__)
        NSEnumerator *enumerator = [attributeDict keyEnumerator];
        NSString *key;
        while (key = [enumerator nextObject]) {
#else
        for (NSString *key in attributeDict) {
#endif
            if ([key isEqualToString: @"CodeA"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setCodeA: val]) {
                   return NO;
                }
                if (![self setCodeA: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"CodeB"]) {
                NSString *val = [attributeDict objectForKey: key];
                if (![self setCodeB: val]) {
                   return NO;
                }
                if (![self setCodeB: val]) {
                   return NO;
                }
            }
            else if ([key isEqualToString:@"Mode"]) {
                NSString *value = [attributeDict objectForKey: key];
                int val = [value intValue];
                if (![self setMode: val]) {
                   return NO;
                }
                if (![self setMode: val]) {
                   return NO;
                }
            }
        }
        return YES;
}

-(NSString *) XML {

    NSMutableString *xml = [NSMutableString stringWithString:@"<UnType"];
    if ( m_codeAPresent ) {
        [xml appendString: @" CodeA=\""];
        [xml appendString: [self encode: m_codeA]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"CodeA" forKey: @"description"]];
        return nil;
    }
    if ( [self hasCodeB] ) {
        [xml appendString: @" CodeB=\""];
        [xml appendString: [self encode: m_codeB]];
        [xml appendString: @"\""];
    }
    if ( m_modePresent ) {
        [xml appendString: @" Mode=\""];
        [xml appendString: [NSString stringWithFormat:@"%d", m_mode]];
        [xml appendString: @"\""];
    } else { // required element is missing !
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ILValidationError" object: self userInfo: [NSDictionary dictionaryWithObject: @"Mode" forKey: @"description"]];
        return nil;
    }
    [xml appendString:@"/>\n"];
    return xml;
}

-(NSString *) encode: (NSString *) input {

    NSMutableString *str = [[[NSMutableString alloc] initWithString: input] autorelease];

    [str replaceOccurrencesOfString: @"&" withString: @"&amp;" options: NSCaseInsensitiveSearch range: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @"<" withString: @"&lt;" options: NSCaseInsensitiveSearch range: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @">" withString: @"&gt;" options: NSCaseInsensitiveSearch range: NSMakeRange(0, [str length])];
    [str replaceOccurrencesOfString: @"\"" withString: @"&quot;" options: NSCaseInsensitiveSearch range: NSMakeRange(0, [str length])];

    return str;
}

-(NSString *) stringValue {

    return [self stringValueWithLead:@""];
}

-(NSString *) stringValueWithLead: (NSString *) lead {

    NSMutableString *str = [[[NSMutableString alloc] init] autorelease];
    [str setString: [lead stringByAppendingString:@"UnType\n"]];
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"CodeA = "];
    [str appendString: m_codeA];
    [str appendString: @"\n"];

    if ( [self hasCodeB] ) {
        [str appendString: [lead stringByAppendingString: @" "]];
        [str appendString: @"CodeB = "];
        [str appendString: m_codeB];
        [str appendString: @"\n"];

    }
    [str appendString: [lead stringByAppendingString: @" "]];
    [str appendString: @"Mode = "];
    [str appendString: [NSString stringWithFormat:@"%d", m_mode]];
    [str appendString: @"\n"];

    return str;
}

-(NSDictionary *) attributes {

    NSMutableDictionary *attr = [[[NSMutableDictionary alloc] init] autorelease];
    [attr setObject: m_codeA forKey: @"CodeA"];
    if ( [self hasCodeB] ) {
        [attr setObject: m_codeB forKey: @"CodeB"];
    }
    [attr setObject: [NSString stringWithFormat:@"%d", m_mode] forKey: @"Mode"];

    return attr;
}


@end


