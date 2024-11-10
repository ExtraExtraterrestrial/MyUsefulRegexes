(?<origin>(?<protocol>https?):\/\/(?<hostname>(?<subdomain>[a-z0-9\-\.]*?)\.?(?<sld>[a-z0-9\-]+)\.(?<tld>(?:(?:co|com|org|gov|net|ed|edu)\.[a-z]{2})|xn--[a-z0-9\-]{2,}|[a-z]{2,})))(?=\/|$)(?:(?<pathname>[^\s?]*)(?<search>\?[^\s]*))?
(?<key>[a-zA-Z_][\w%]*)=(?<value>[^\s&]*)

Regex to parse URL parameters on line 2

Groups
	- origin		// JS - location.origin
	- protocol		// JS - locaiton.protocol
	- hostname		// JS - location.host / location.hostname
	- subdomain
	- sld
	- tld
	- pathname		// JS - location.pathname
	- search		// JS - location.search (URL parameters) 

Warning:
	This checks only lower-case letters, use the -i flag in case a case-insensitive check is needed.


(?<origin>											- location.origin
	(?<protocol>https?):\/\/						- get the protocol
	(?<hostname>										- location.host
		(?<subdomain>[a-z0-9\-\.]*?)					- get the subdomains 
														\- sld and tld push the subdomain back as far as possible thanks to *?
		\.?
		(?<sld>[a-z0-9\-]+)								- get sld
		\.
		(?<tld>(?:										- get tld 
														\- in case of a list of tlds, you can use tld1|tld2|... syntax instead of these lines
			(?:co|com|org|gov|net|edu)\.[a-z]{2})			- get a double domain for the most common double TLDs 
			|xn--[a-z0-9\-]{2,}								- or get a punycode tld
			|[a-z]{2,}										- or get a normal tld
		)
	)
)
(?=\/|$)
(?<pathname>[^\s?]*)								- get path (includes initial /)
(?<search>\??[^\s]*)								- get URL parameters (includes initial ?)
