/*
 * Copyright (C) 2022 the original author or authors.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

package party.iroiro.luajava.lua53;

/**
 * Generated with <code>generate-consts.awk</code>:
 * <pre><code>awk -f scripts/generate-consts.awk \
 *     .../lua.h \
 *     .../lauxlib.h \
 *     &gt; .../party/iroiro/jua/...Consts.java</code></pre>
 */
public abstract class Lua53Consts {
    /**
     * Generated from lua53/jni/lua53/lua.h (line 18):
     * <pre><code>#define LUA_VERSION_MAJOR	"5"</code></pre>
     */
    public static final String LUA_VERSION_MAJOR = "5";

    /**
     * Generated from lua53/jni/lua53/lua.h (line 19):
     * <pre><code>#define LUA_VERSION_MINOR	"3"</code></pre>
     */
    public static final String LUA_VERSION_MINOR = "3";

    /**
     * Generated from lua53/jni/lua53/lua.h (line 20):
     * <pre><code>#define LUA_VERSION_NUM		503</code></pre>
     */
    public static final int LUA_VERSION_NUM = 503;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 21):
     * <pre><code>#define LUA_VERSION_RELEASE	"6"</code></pre>
     */
    public static final String LUA_VERSION_RELEASE = "6";

    /**
     * Generated from lua53/jni/lua53/lua.h (line 26):
     * <pre><code>#define LUA_AUTHORS	"R. Ierusalimschy, L. H. de Figueiredo, W. Celes"</code></pre>
     */
    public static final String LUA_AUTHORS = "R. Ierusalimschy, L. H. de Figueiredo, W. Celes";

    /**
     * Generated from lua53/jni/lua53/lua.h (line 30):
     * <pre><code>#define LUA_SIGNATURE	"\x1bLua"</code></pre>
     */
    public static final String LUA_SIGNATURE = "\u001bLua";

    /**
     * Generated from lua53/jni/lua53/lua.h (line 33):
     * <pre><code>#define LUA_MULTRET	(-1)</code></pre>
     */
    public static final int LUA_MULTRET = (-1);

    /**
     * Generated from lua53/jni/lua53/lua.h (line 46):
     * <pre><code>#define LUA_OK		0</code></pre>
     */
    public static final int LUA_OK = 0;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 47):
     * <pre><code>#define LUA_YIELD	1</code></pre>
     */
    public static final int LUA_YIELD = 1;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 48):
     * <pre><code>#define LUA_ERRRUN	2</code></pre>
     */
    public static final int LUA_ERRRUN = 2;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 49):
     * <pre><code>#define LUA_ERRSYNTAX	3</code></pre>
     */
    public static final int LUA_ERRSYNTAX = 3;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 50):
     * <pre><code>#define LUA_ERRMEM	4</code></pre>
     */
    public static final int LUA_ERRMEM = 4;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 51):
     * <pre><code>#define LUA_ERRGCMM	5</code></pre>
     */
    public static final int LUA_ERRGCMM = 5;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 52):
     * <pre><code>#define LUA_ERRERR	6</code></pre>
     */
    public static final int LUA_ERRERR = 6;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 61):
     * <pre><code>#define LUA_TNONE		(-1)</code></pre>
     */
    public static final int LUA_TNONE = (-1);

    /**
     * Generated from lua53/jni/lua53/lua.h (line 63):
     * <pre><code>#define LUA_TNIL		0</code></pre>
     */
    public static final int LUA_TNIL = 0;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 64):
     * <pre><code>#define LUA_TBOOLEAN		1</code></pre>
     */
    public static final int LUA_TBOOLEAN = 1;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 65):
     * <pre><code>#define LUA_TLIGHTUSERDATA	2</code></pre>
     */
    public static final int LUA_TLIGHTUSERDATA = 2;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 66):
     * <pre><code>#define LUA_TNUMBER		3</code></pre>
     */
    public static final int LUA_TNUMBER = 3;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 67):
     * <pre><code>#define LUA_TSTRING		4</code></pre>
     */
    public static final int LUA_TSTRING = 4;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 68):
     * <pre><code>#define LUA_TTABLE		5</code></pre>
     */
    public static final int LUA_TTABLE = 5;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 69):
     * <pre><code>#define LUA_TFUNCTION		6</code></pre>
     */
    public static final int LUA_TFUNCTION = 6;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 70):
     * <pre><code>#define LUA_TUSERDATA		7</code></pre>
     */
    public static final int LUA_TUSERDATA = 7;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 71):
     * <pre><code>#define LUA_TTHREAD		8</code></pre>
     */
    public static final int LUA_TTHREAD = 8;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 73):
     * <pre><code>#define LUA_NUMTAGS		9</code></pre>
     */
    public static final int LUA_NUMTAGS = 9;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 78):
     * <pre><code>#define LUA_MINSTACK	20</code></pre>
     */
    public static final int LUA_MINSTACK = 20;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 82):
     * <pre><code>#define LUA_RIDX_MAINTHREAD	1</code></pre>
     */
    public static final int LUA_RIDX_MAINTHREAD = 1;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 83):
     * <pre><code>#define LUA_RIDX_GLOBALS	2</code></pre>
     */
    public static final int LUA_RIDX_GLOBALS = 2;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 196):
     * <pre><code>#define LUA_OPSUB	1</code></pre>
     */
    public static final int LUA_OPSUB = 1;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 197):
     * <pre><code>#define LUA_OPMUL	2</code></pre>
     */
    public static final int LUA_OPMUL = 2;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 198):
     * <pre><code>#define LUA_OPMOD	3</code></pre>
     */
    public static final int LUA_OPMOD = 3;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 199):
     * <pre><code>#define LUA_OPPOW	4</code></pre>
     */
    public static final int LUA_OPPOW = 4;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 200):
     * <pre><code>#define LUA_OPDIV	5</code></pre>
     */
    public static final int LUA_OPDIV = 5;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 201):
     * <pre><code>#define LUA_OPIDIV	6</code></pre>
     */
    public static final int LUA_OPIDIV = 6;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 202):
     * <pre><code>#define LUA_OPBAND	7</code></pre>
     */
    public static final int LUA_OPBAND = 7;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 203):
     * <pre><code>#define LUA_OPBOR	8</code></pre>
     */
    public static final int LUA_OPBOR = 8;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 204):
     * <pre><code>#define LUA_OPBXOR	9</code></pre>
     */
    public static final int LUA_OPBXOR = 9;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 205):
     * <pre><code>#define LUA_OPSHL	10</code></pre>
     */
    public static final int LUA_OPSHL = 10;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 206):
     * <pre><code>#define LUA_OPSHR	11</code></pre>
     */
    public static final int LUA_OPSHR = 11;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 207):
     * <pre><code>#define LUA_OPUNM	12</code></pre>
     */
    public static final int LUA_OPUNM = 12;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 208):
     * <pre><code>#define LUA_OPBNOT	13</code></pre>
     */
    public static final int LUA_OPBNOT = 13;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 212):
     * <pre><code>#define LUA_OPEQ	0</code></pre>
     */
    public static final int LUA_OPEQ = 0;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 213):
     * <pre><code>#define LUA_OPLT	1</code></pre>
     */
    public static final int LUA_OPLT = 1;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 214):
     * <pre><code>#define LUA_OPLE	2</code></pre>
     */
    public static final int LUA_OPLE = 2;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 301):
     * <pre><code>#define LUA_GCSTOP		0</code></pre>
     */
    public static final int LUA_GCSTOP = 0;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 302):
     * <pre><code>#define LUA_GCRESTART		1</code></pre>
     */
    public static final int LUA_GCRESTART = 1;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 303):
     * <pre><code>#define LUA_GCCOLLECT		2</code></pre>
     */
    public static final int LUA_GCCOLLECT = 2;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 304):
     * <pre><code>#define LUA_GCCOUNT		3</code></pre>
     */
    public static final int LUA_GCCOUNT = 3;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 305):
     * <pre><code>#define LUA_GCCOUNTB		4</code></pre>
     */
    public static final int LUA_GCCOUNTB = 4;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 306):
     * <pre><code>#define LUA_GCSTEP		5</code></pre>
     */
    public static final int LUA_GCSTEP = 5;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 307):
     * <pre><code>#define LUA_GCSETPAUSE		6</code></pre>
     */
    public static final int LUA_GCSETPAUSE = 6;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 308):
     * <pre><code>#define LUA_GCSETSTEPMUL	7</code></pre>
     */
    public static final int LUA_GCSETSTEPMUL = 7;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 309):
     * <pre><code>#define LUA_GCISRUNNING		9</code></pre>
     */
    public static final int LUA_GCISRUNNING = 9;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 401):
     * <pre><code>#define LUA_HOOKCALL	0</code></pre>
     */
    public static final int LUA_HOOKCALL = 0;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 402):
     * <pre><code>#define LUA_HOOKRET	1</code></pre>
     */
    public static final int LUA_HOOKRET = 1;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 403):
     * <pre><code>#define LUA_HOOKLINE	2</code></pre>
     */
    public static final int LUA_HOOKLINE = 2;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 404):
     * <pre><code>#define LUA_HOOKCOUNT	3</code></pre>
     */
    public static final int LUA_HOOKCOUNT = 3;

    /**
     * Generated from lua53/jni/lua53/lua.h (line 405):
     * <pre><code>#define LUA_HOOKTAILCALL 4</code></pre>
     */
    public static final int LUA_HOOKTAILCALL = 4;

    /**
     * Generated from lua53/jni/lua53/lauxlib.h (line 509):
     * <pre><code>#define LUA_LOADED_TABLE	"_LOADED"</code></pre>
     */
    public static final String LUA_LOADED_TABLE = "_LOADED";

    /**
     * Generated from lua53/jni/lua53/lauxlib.h (line 513):
     * <pre><code>#define LUA_PRELOAD_TABLE	"_PRELOAD"</code></pre>
     */
    public static final String LUA_PRELOAD_TABLE = "_PRELOAD";

    /**
     * Generated from lua53/jni/lua53/lauxlib.h (line 562):
     * <pre><code>#define LUA_NOREF       (-2)</code></pre>
     */
    public static final int LUA_NOREF = (-2);

    /**
     * Generated from lua53/jni/lua53/lauxlib.h (line 563):
     * <pre><code>#define LUA_REFNIL      (-1)</code></pre>
     */
    public static final int LUA_REFNIL = (-1);

    /**
     * Generated from lua53/jni/lua53/lauxlib.h (line 675):
     * <pre><code>#define LUA_FILEHANDLE          "FILE*"</code></pre>
     */
    public static final String LUA_FILEHANDLE = "FILE*";

}
