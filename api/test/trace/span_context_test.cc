#include "opentelemetry/trace/span_context.h"
#include "opentelemetry/trace/span_id.h"
#include "opentelemetry/trace/trace_id.h"

#include <gtest/gtest.h>

using opentelemetry::trace::SpanReference;

TEST(SpanReferenceTest, IsSampled)
{
  SpanReference s1(true, true);

  ASSERT_EQ(s1.IsSampled(), true);

  SpanReference s2(false, true);

  ASSERT_EQ(s2.IsSampled(), false);
}

TEST(SpanReferenceTest, HasRemoteParent)
{
  SpanReference s1(true, true);

  ASSERT_EQ(s1.HasRemoteParent(), true);

  SpanReference s2(true, false);

  ASSERT_EQ(s2.HasRemoteParent(), false);
}

TEST(SpanReferenceTest, TraceFlags)
{
  SpanReference s1(true, true);

  ASSERT_EQ(s1.trace_flags().flags(), 1);

  SpanReference s2(false, true);

  ASSERT_EQ(s2.trace_flags().flags(), 0);
}

// Test that SpanReference is invalid
TEST(SpanReferenceTest, Invalid)
{
  SpanReference s1 = SpanReference::GetInvalid();
  EXPECT_FALSE(s1.IsValid());

  // Test that trace id and span id are invalid
  EXPECT_EQ(s1.trace_id(), opentelemetry::trace::TraceId());
  EXPECT_EQ(s1.span_id(), opentelemetry::trace::SpanId());
}
